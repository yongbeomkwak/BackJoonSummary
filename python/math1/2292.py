def cal(a:int)->int:
   c=0
   if a>1:
      for i in range(1,a+1):
         if((3*i*i)+(-3*i)+1)>=a:
            c=i
            return c
   return 1

if __name__ == "__main__":
   a=int(input())
   print(cal(a))



              
              
