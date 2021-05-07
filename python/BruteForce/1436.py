
def checkEndNumber(num:str) ->bool:
    return True if "666" in num else False
    # num 문자가 666d을 포함하고 있으면 return true
if __name__ == "__main__":
    num=int(input())
    start=665
    count=0
    while (count!=num):
        start+=1
        if(checkEndNumber(str(start))):
            count+=1
       
    print(start)