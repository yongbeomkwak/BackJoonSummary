import sys

if __name__ == "__main__":
    str_in = sys.stdin.readline().split(" ")
    n = int(str_in[0])
    x = int(str_in[1])
    a = sys.stdin.readline().split(" ")
    result=list()
    for val in  a:
        value=int(val)
        if(x>value):
            result.append(value)
    
    for val in result:
        print(val, end=' ')
        

