import sys

if __name__ == "__main__":
  count=int(input())

  _list=list(map(int,input().split())) # input으로 받은 입력 값들을 띄어쓰기를 기준으로 자른 후,int로 변환하여 list로 바꿈
  _list.sort()
  max_value=_list[count-1]

  avg=0
  for val in _list:
      avg+=val/max_value *100

  print(avg/count)
