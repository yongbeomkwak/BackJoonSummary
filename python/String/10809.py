import sys


if __name__ == "__main__":
    num=input()
    a=[-1 for  i in range(26)]
    
    index=0
    for val in num:
      if (a[ord(val)-97]==-1):  # a == Ascii (97)
        a[ord(val)-97]=index

      index+=1

    for val in a:
      print(val,end=" ")