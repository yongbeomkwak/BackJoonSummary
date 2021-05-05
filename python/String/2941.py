import sys
if __name__ == "__main__":
    num = input()
    end = len(num)-1
    count = 0
    index = 0
    while index <= end:
        curr = num[index]
        if curr == "c":
            next_str = num[index+1] if (index+1 <= end) else num[index]
            if(next_str == "=" or next_str == "-"):
                count += 1
                index += 2
                continue
            else:
                count += 1
                index += 1
                continue
        elif curr == "d":
            next_str = num[index+1] if (index+1 <= end) else num[index]
            if next_str == "-":
                count += 1
                index += 2
                continue
            elif next_str == "z":
                nnext_str = num[index+2] if (index+2 <= end) else num[index+1]
                if nnext_str == "=":
                    count += 1
                    index += 3
                    continue
                else:
                    count += 1
                    index += 1
                    continue
            else:
                count += 1
                index += 1
                continue
        elif curr == "l" or curr == "n":
            next_str = num[index+1] if (index+1 <= end) else num[index]
            if next_str == "j":
                count += 1
                index += 2
                continue
            else:
                count += 1
                index += 1
                continue
        elif curr == "s" or curr == "z":
            next_str = num[index+1] if (index+1 <= end) else num[index]

            if next_str == "=":
                count += 1
                index += 2
                continue
            else:
                count += 1
                index += 1
        else:
            count += 1
            index += 1
    print(count)
