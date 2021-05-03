import sys

if __name__ == "__main__":
    a=int(sys.stdin.readline())
    b=0
    final=a
    while(1):
        b+=1
        c=final//10
        d=final%10 #다음 수의 십의 자리
        e=(c+d)%10  #다음 수의 일의 자리
        final=(d*10)+e
        if(a==final):
            print(b)
            break
        else:
            continue

        
