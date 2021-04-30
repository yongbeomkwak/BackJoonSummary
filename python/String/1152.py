if __name__=="__main__":
    str_in=input() #입력 받고 
    list_str=str_in.split(" ") # " "띄어쓰기로 구분하여 리스트를만듬
    result=0 
    for val in list_str:
        if(val!=''): # 만약 list 해당 값임 빈칸이 아니면 단어이기 때문에 +1 
            result+=1
    print(result)
