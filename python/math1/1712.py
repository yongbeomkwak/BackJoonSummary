if __name__ == "__main__":
   in_list=list(map(int,input().split(" ")))
   A=in_list[0]
   B=in_list[1]
   C=in_list[2]
   if(B>=C):
      print(-1)
   else:
      print(A//(C-B)+1)



              
              
