import sys
sys.setrecursionlimit(2500)

if __name__ == "__main__":
    tc=int(input())
    in_list=list()
    for i in range(tc):
        in_list.append(list(map(int,input().split(" "))))
    

    
    final_list=sorted(in_list,key= lambda xy:(xy[0],xy[1]))
    
    for result in final_list:
        print(result[0],result[1])