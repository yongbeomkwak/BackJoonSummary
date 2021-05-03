import sys

if __name__ == "__main__":
    
    while(1):
        str_in = sys.stdin.readline().split(" ")
        a = int(str_in[0])
        b = int(str_in[1])
        if(a==0 and b==0):
            break
        print(a+b)
        

