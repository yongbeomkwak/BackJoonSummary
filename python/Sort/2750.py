
if __name__ == "__main__":
    num=int(input())
    in_list=list()
    for i in range(num):
        in_list.append(int(input()))
    
    in_list.sort()
    for val in in_list:
        print(val)  