import sys


if __name__ == "__main__":
    doc = sys.stdin.readline().rstrip()
    word = sys.stdin.readline().rstrip()
    answer = 0
    i = 0
    print(doc,word)
    while i != len(doc):
        for j in range(len(word)):
            if(i+j >= len(doc)):
                i += 1
                break
            else:
                if(doc[i+j] != word[j]):
                    i += 1
                    break
                else:
                    if(j == len(word)-1):
                        answer += 1
                        i = (i+j+1)
    print(answer)
