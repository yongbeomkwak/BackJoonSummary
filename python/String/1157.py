import sys


if __name__ == "__main__":
    spell = list()
    for i in range(65, 91):  # A(65)->Z(90)
        spell.append(chr(i))
    # 스펠링을 key로 value를 0으로 dictionary 만듬
    mapp = {key: 0 for key in spell}
    str_in = input() 
    
    for val in str_in: #입력 받은 글자 하나하나를 대문자로 만들어 키로 전달, 해당 키에 해당하는 value 증가
        mapp[val.upper()] += 1
    max_count = max(mapp.values()) # value중 max 값 추출
    max_key = ''
    check = 0 #두개 이상의 최댓값 확인 여부
    for key, val in mapp.items(): #.items()를 해야 key와 value 받아옴
        if(val == max_count):
            max_key = key # 해당 key 저장 
            check += 1

    if(check > 1): # 1보다 크다는 것은 최대 중복 글자가 1개 이상이라는 것 
        print("?")
    else:
        print(max_key)
