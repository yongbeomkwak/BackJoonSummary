import sys
sys.setrecursionlimit(2500)
MAX=21
existTeam=[False for i in range(MAX)]
s=[[] for i in range(MAX)]
n=0
Tgap=9999999

def DFS(nowPlayer:int,playerCount:int):
    global Tgap
    global s
    global existTeam
    global n
    if(playerCount==n//2):
        star_team=list()
        link_team=list()
        for i in range(n):
            if(existTeam[i]):
                star_team.append(i)
            else:
                link_team.append(i)
        
        star_teamPoint=0
        link_teamPoint=0

        for i in range(len(star_team)):
            for j in range(i+1,len(star_team)):
                star_i=star_team[i]
                star_j=star_team[j]
                link_i=link_team[i]
                link_j=link_team[j]
                star_teamPoint+=s[star_i][star_j]+s[star_j][star_i]
                link_teamPoint+=s[link_i][link_j]+s[link_j][link_i]
        curr_Tgap=abs(star_teamPoint-link_teamPoint)
        Tgap=min(Tgap,curr_Tgap)

    else:
            for i in range(nowPlayer+1,n):
                if existTeam[i]==False:
                    existTeam[i]=True
                    DFS(i,playerCount+1)
                    existTeam[i]=False
if __name__ == "__main__":
    n=int(input())


    for i in range(n):
        s[i]=list(map(int,input().split(" "))) 
    DFS(0,0)
    print(Tgap)
