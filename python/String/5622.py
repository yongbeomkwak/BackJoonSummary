import sys

def dialog(num):
   if(num<='O'):
      count=((ord(num)-65)//3)+3
   elif(num>='P' and num<='S'):
      count=8
   elif(num>='T' and num<='V'):
      count=9
   else:
      count=10   

   return count


if __name__ == "__main__":
   num=input()
   time=0
   for val in num:
      time+=dialog(val) 
   
   print(time)