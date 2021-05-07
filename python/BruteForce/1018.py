min_value=9999
if __name__ == "__main__":
    M, N = map(int, input().split())
    chase = list()
    for i in range(M):
        temp = input()
        chase.append(temp)
    W = list()
    B = list()
    for i in range(8):
        if(i % 2 == 0):
            W.append("W")
        else:
            W.append("B")
    for i in range(8):
        if(i % 2 == 0):
            B.append("B")
        else:
            B.append("W")
    print(W,B)
    for p in range(M-7):   
            for q in range(N-7):
                    start = chase[p][q]
                    white_count = 0
                    black_count = 0
                    for i in range(p,p+8):
                        for j in range(q,q+8):
                            if(i % 2 == 0):
                                if(chase[i][j] != W[j-q]):
                                    white_count += 1
                                if(chase[i][j] != B[j-q]):
                                    black_count += 1
                            else:
                                if(chase[i][j] != B[j-q]):
                                    white_count += 1
                                if(chase[i][j] != W[j-q]):
                                    black_count += 1
                    temp=white_count if white_count<black_count else black_count
             
                    min_value=temp if min_value>temp else min_value
    print(min_value)