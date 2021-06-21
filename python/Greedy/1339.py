import sys

if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    answer=0
    alpha=[0 for _ in range(26)]
    _str=list()
    for _ in range(N):
        _str.append(sys.stdin.readline().rsplit()[0]) # \n 을 없앤 리스트 형태에서 실제 문자열(str 값음) 0 번 째 인덱스
    
    for s in _str:
        size=pow(10,len(s)-1)
        for c in s:
            alpha[ord(c)-65]+=size  # ord() -> char to ascii  'A'=65
            size//=10
    alpha.sort(reverse=True) #내림 차순
    const=9
    for i in range(26):
        if(alpha[i]==0):
            break
        answer+=alpha[i]*const
        const-=1
    print(answer)


        


