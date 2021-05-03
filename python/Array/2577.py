import sys

if __name__ == "__main__":
    a=int(input())
    b=int(input())
    c=int(input())
    d=a*b*c
    str_d=str(d)
    arr = [0,0,0,0,0,0,0,0,0,0]
    for val in str_d:
        arr[int(val)]+=1
    
    for val in arr:
        print(val)
    