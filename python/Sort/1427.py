import sys
sys.setrecursionlimit(2500)

if __name__ == "__main__":
    num=input()
    num_list=list()
    for val in num:
        num_list.append(val)
    num_list.sort(reverse=True)
    
    for val in num_list:
        print(val,end="")
    