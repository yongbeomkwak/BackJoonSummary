import sys
sys.setrecursionlimit(2500)

if __name__ == "__main__":
    num = int(input())
    max_val = -9999
    min_val = 9999
    mode = 0  # 최빈값
    mid = 0  # 중앙값
    Amean = 0  # 산술평균(모든 수의합/수의 개수)
    in_dict = dict()
    count_mid = (num//2)+1
    for i in range(num):
        temp = int(input())
        Amean+=temp
        if(temp in in_dict):
            in_dict[temp]=in_dict[temp]+1
        else:
            in_dict[temp]=1
        if temp > max_val:
            max_val = temp
        if temp < min_val:
            min_val = temp

    final_list=list()
    for key,val in in_dict.items():
        final_list.append([key,val])
    mode_list=sorted(final_list,key=lambda count:(count[1],-count[0]))
    #key= lamda 변수 :(정렬기준1,정렬기준2...) ,key는 정렬 기준이 들어간다
    #여기서 lamda count에서 count는 final_list를 가르키고,처음에는 count[1] 값으로 오름차순 정렬 ,2번쨔로 count[1] 가지고 내림차순
    #정렬 시 -가 붙으면 내림차순
    mode=mode_list[0][0]
    
    if len(mode_list)>1:
        if(mode_list[0][1]==mode_list[1][1]):
            if mode_list[0][0]<mode_list[1][0]:
                mode=mode_list[1][0]
    midle_list=sorted(final_list,key= lambda keys:keys[0])
    count=0
    for sec_list in midle_list:
        count+=sec_list[1]
        if(count>=count_mid):
            mid=sec_list[0]
            break
    print("{0}\n{1}\n{2}\n{3}".format(Amean//num,mid,mode,max_val-min_val))
    