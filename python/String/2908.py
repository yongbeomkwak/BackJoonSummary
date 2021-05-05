import sys


if __name__ == "__main__":
    num_list=list(map(str,input().split(" ")))
    a=list(reversed(num_list[0]))
    b=list(reversed(num_list[1]))
    c=0
    d=0
    for i  in range(0,3):
       c+=int(a[i]) * pow(10,2-i) #0번째는 100의 자리,1번째는 10자리 
       d+=int(b[i]) * pow(10,2-i)
    

    print(c if c>d else d) #true vale if(condition) else false value
    
    
