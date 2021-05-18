import sys
sys.setrecursionlimit(2500)
LMIT = 1000
# dp = [ 1 for _ in range(LMIT)]
in_list =[]
curr=0

if __name__ == "__main__":
    n = int(input())
    
    in_list=list(map(int,input().split()))
    reverse_in_list=in_list[::-1]

    dp = [ 0 for _ in range(n)]   
    dp_increase = [ 1 for _ in range(n)]   # 가장 긴 증가하는 부분 수열
    dp_decrease = [ 1 for _ in range(n)]   # 가장 긴 감소하는 부분 수열(reversed)

###  in_list=1 2 3 4 5
### reverse_in_list 5 4 3 2 1

    for i in range(n):
        for j in range(i):
            if in_list[i]> in_list[j]: #증가 수열 
                dp_increase[i]=max(dp_increase[i],dp_increase[j]+1)
            if reverse_in_list[i]>reverse_in_list[j]: #감소 수열
                dp_decrease[i]=max(dp_decrease[i],dp_decrease[j]+1)
    
    for i in range(n):             #n-1-i(n-1)끝 -i(거꾸로 세기) -1(겹치는 부분이 두번 카운트 되므로 -1)
        dp[i]=dp_increase[i]+dp_decrease[n-1-i]-1   #increase[0] 과 decrease[n-1] 과 매칭됨, decrease는 reverse 에서 카운트 했기 때문
    
    print(max(dp))



