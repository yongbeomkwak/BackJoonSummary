result=1000001
def partialSum(n:int):
    global result
    for i in range(n,0,-1):
        str_n=str(i) #해당 입력 부터 내려가고 ,일단 반복을 위해 문자열로 만든
        curr=i  #초기 값은 일단 자기자신을 넣어준 후 
        for j in str_n: # 여기서 int(j)는 각 자리수에 해당되는 숫자고
            curr+=int(j)
        
        if(curr==n and result>=i): #그 전의 결과값 result보다 작고 생성자가 맞다면
            result=i #결과값 수정
        
    



if __name__ == "__main__":
    num=int(input())
    partialSum(num)
    print(result) if result!=1000001 else print(0) #만약 result의 값이 10000001으로 부터 변화가 없다는 것은 생성자가 없다는 뜻 그러므로 0출력
        


