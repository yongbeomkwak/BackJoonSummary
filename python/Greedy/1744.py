import sys


if __name__ == "__main__":
    N = int(sys.stdin.readline().rstrip())
    v1 = []
    v2 = []
    result = 0
    for _ in range(N):
        temp = int(sys.stdin.readline().rstrip())
        if(temp > 0):
            v1.append(temp)
        else:
            v2.append(temp)
    v1.sort()
    v2.sort(reverse=True)
    while len(v1) > 1:
        temp1 = v1[-1]
        v1.pop(-1)
        temp2 = v1[-1]
        v1.pop(-1)
        if(temp1 != 1 and temp2 != 1):
            result += temp1*temp2
        else:
            result += (temp1+temp2)
    if(len(v1) == 1):
        result += v1[0]

    while len(v2) > 1:
        temp1 = v2[-1]
        v2.pop(-1)
        temp2 = v2[-1]
        v2.pop(-1)
        if(temp1*temp2 >= 0):
            result += temp1*temp2
        else:
            result += (temp1+temp2)
    if(len(v2) == 1):
        result += v2[0]
    print(result)
