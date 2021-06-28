import sys

def calchange(change:int):
    temp=change
    change_list=[25,10,5,1]
    n_change_list=[0,0,0,0]

    for i in range(4):
        n_change_list[i]=temp//change_list[i]
        temp%=change_list[i]
    print(n_change_list[0],n_change_list[1],n_change_list[2],n_change_list[3])


if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    for _ in range(N):
        calchange(int(sys.stdin.readline().rstrip()))
