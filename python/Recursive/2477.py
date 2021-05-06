def solve(x:int,y:int,n:int,star:list):
    if(n==3):
        for i in range(3):
            for j in range(3):
                if(i==1 and j==1):
                    star[x+i][y+j]=" "
                    continue
                star[x+i][y+j]="*"
        return
    
    m=n//3
    for i in range(3):
        for j in range(3):
            if(i==1 and j==1):
                continue 
            solve(x+i*m,y+j*m,m,star)

if __name__ == "__main__":
    num=int(input())
    star=[list() for i in range(num)] #2차원 배열 만든 후 
    for i in range(num):
        star[i]=[" " for j in range(num)]
    #1차원 배열 값 ' '으로 초기화 하기
    solve(0,0,num,star)

    for i in range(num):
        for j in range(num):
            print(star[i][j],end="")
        print()


            
              
