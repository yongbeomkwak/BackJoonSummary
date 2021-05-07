
if __name__ == "__main__":
    tc=int(input())
    in_list=list()
    for i in range(tc):
        w_h_list=list(map(int,input().split(" ")))
        in_list.append(w_h_list)
    
    result_list=list()
    fin=len(in_list)
    for i in in_list:
        count =1
        for j in in_list:
            if(i!=j):
                if(i[0]<j[0] and i[1]<j[1]):
                    count+=1
        
        result_list.append(count)
    for val in result_list:
        print(val,end=" ")