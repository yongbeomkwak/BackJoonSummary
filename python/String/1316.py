if __name__ == "__main__":
   tc = int(input())
   count = 0
   for i in range(tc): 
      str_in = input() #문자를 입력받음 
      end_index = len(str_in)-1 # 끝 인덱스 
      last_check=True #최종 플래그 , 이 값이 True면 그룹 단어
      for st in range(0, end_index+1): #앞에서부터 전진 
         check=True #뒤에서 부터 돌 때 가르키는 값과 같은 문자를 처음 만날 때 flag 꺼짐
         second_check=False #check 가 꺼진 후 다른 값과 만날 때 flag 켜짐, 이 다음에 만약 또 같은 값만나면 그룹단어 아님 
         
         for ed in range(end_index, st-1, -1): #뒤부터 현재 가르키는 위치까지 돔
            if((str_in[st] == str_in[ed]) and check == True and second_check == False): #처음 같은 값 만날 때
               check = False #플래그 꺼짐 
            elif ((str_in[st] != str_in[ed]) and check == False and second_check == False):
               second_check = True # 같은 값이 아닌 값 감지 즉 이 다음 부터 같은 값 만나면 그룹단어 아님
            elif ((str_in[st] == str_in[ed]) and check == False and second_check == True):
               last_check = False # 최종 그룹단어 탈락
               break   
         if(last_check==False): #Break문으로 나왔으니 즉,그룹단어 탈락
            break # 바깥 for문을 돌 필요 없음 
      if(last_check==True): # 검사
         count+=1 #추가 
   print(count)

              
              
