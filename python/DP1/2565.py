import sys
sys.setrecursionlimit(2500)
LMIT = 501
# dp = [ 1 for _ in range(LMIT)]
in_list =[]


a = []
b = []
if __name__ == "__main__":
    n = int(input())
    dp = [ 1 for _ in range(n)]    #자기 자신은 일단 겹치지 않은 전기 줄이라고 생각
    for _ in range(n):   
        in_list.append(list(map(int,input().split())))

    
    in_list.sort()
 
    a_to_b=list(map(lambda x:x[1],in_list))
    
    for i in range(n):
        for j in range(i):
            if a_to_b[i]> a_to_b[j]: #i가 제일 오른쪽에 있다고 생각 하고,j가 작으면 겹치지 않음
                dp[i]=max(dp[i],dp[j]+1) # 해당 i에 겹치지 않은 최대 전기 줄
    
    print(n-max(dp))
            

  





