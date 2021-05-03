import sys

if __name__ == "__main__":
    tc=int(input())
    for i in range(tc):
        input_list=list(map(int,input().split()))
        stu_num=input_list[0] #첫번째 수는 학생수 
        _list=input_list[1:] #인덱스 1번(2번째) 부터 끝까지 따로 slice
        avg=sum(_list)/stu_num
        count=0
        for val in _list:
            if(val>avg):
                count+=1
        result=count/stu_num *100
        print("{:.3f}%".format(result)) # 소수 3째자리 까지 출력
