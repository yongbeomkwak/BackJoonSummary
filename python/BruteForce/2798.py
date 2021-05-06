result=0
M=0
N=0
def BlackJack(fin:int,num:list,summ:int,now:int):
    global result
    global M
    global N
    if(fin==3):
        if(M-summ<=M-result and M-summ>=0): #반복문 시작이 모든 경우를 돌 수 있게, 0~5,1~5,2~5 이런식으로
            result=summ
        return

    else:
        for i in range(now,N):
            BlackJack(fin+1,num,summ+num[i],i+1)

    



if __name__ == "__main__":
    n_m_list=list(map(int,input().split(" ")))
    N=n_m_list[0]
    M=n_m_list[1]
    in_list=list(map(int,input().split()))
    BlackJack(0,in_list,0,0)

    print(result)
    
        


