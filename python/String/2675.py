import sys


if __name__ == "__main__":
    tc = int(input())

    for i in range(tc):
        in_list = list(map(str, input().split(" ")))

        roop = int(in_list[0])
        char = in_list[1]

        for val in char:
            print(val*roop, end='')

        print()   
