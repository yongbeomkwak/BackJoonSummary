import sys
sys.setrecursionlimit(2500)


if __name__ == "__main__":
    N=int(sys.stdin.readline())
    result=0
    mindex=0
    dis=list(map(int,input().split()))
    L=sum(dis)
    grd=list(map(int,input().split()))
    mincost=min(grd)
    mindex=grd.index(mincost)

    if mindex==0:
        result=L*mincost
    else:
        mincost=grd[0]
        result=dis[0]*mincost
        L-=dis[0]
        for i in range(1,mindex):
            if mincost<grd[i]:
                result+=mincost*dis[i]
                L-=dis[i]
            else:
                mincost=grd[i]
                result+=mincost*dis[i]
                L-=dis[i]
        result+=grd[mindex]*L
    print(result)
   