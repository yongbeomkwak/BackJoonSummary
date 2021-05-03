import sys

if __name__ == "__main__":

    while(1):

        try:
            str_in = sys.stdin.readline().split(" ")
            a = int(str_in[0])
            b = int(str_in[1])
            print(a+b)
        except:
            break
        
