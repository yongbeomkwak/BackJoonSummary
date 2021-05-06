def fact(a:int)->int:
    if(a<1):
        return 1
    else:
        return a*fact(a-1)

if __name__ == "__main__":
    a=int(input())
    print(fact(a))



              
              
