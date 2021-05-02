

if __name__ == "__main__":
    time=input().split(" ")
    h=int(time[0])
    m=int(time[1])
    mm=m-45
    if(mm>=0):
        print(h,mm)
    else:
        new_m=60-abs(mm)
        new_h=h-1
        if(new_h>=0):
            print(new_h,new_m)
        else:
            print(23,new_m)


    