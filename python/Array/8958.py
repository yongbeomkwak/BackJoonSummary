import sys

if __name__ == "__main__":
    tc=int(input())
    for i in range(tc):
        _str=input()
        prev_score=0
        total=0
        for val in _str:
            if(val=='O'):
                prev_score+=1
                total+=prev_score
            else:
                prev_score=0
        print(total)
