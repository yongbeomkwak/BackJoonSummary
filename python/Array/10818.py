import sys

if __name__ == "__main__":
    a=int(sys.stdin.readline())
    arr=list()
    b=sys.stdin.readline().split(" ")

    for val in b:
        arr.append(int(val))
    print(min(arr),max(arr))
    
        
