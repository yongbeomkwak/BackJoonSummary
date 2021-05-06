
def move(start:int,dest:int):
    print(start,dest)

def hanoi(N:int,start:int,via:int,dest:int):
    if N==1:
        move(start,dest)
        return
    else:
        hanoi(N-1,start,dest,via)
        move(start,dest)
        hanoi(N-1,via,start,dest)


if __name__ == "__main__":
    num=int(input())
    print(pow(2,num)-1)
    hanoi(num,1,2,3)



            
              
