import sys

if __name__ == "__main__":
    
    count=0
    arr = [0 for i in range(42)]  # 42개 까지 요소를 0으로 초기화
    
    for val in range(10):
        a=int(input())
        if(arr[a%42]==0):
            arr[a%42]=1
        
    
    for val in arr:
        count+=val
    
    print(count)
    