def fibo(a:int)->int:
    if(a==0):
        return 0
    elif(a<2):
        return 1
    else:
        return fibo(a-1)+fibo(a-2)

if __name__ == "__main__":
    a=int(input())
    print(fibo(a))



              
              
