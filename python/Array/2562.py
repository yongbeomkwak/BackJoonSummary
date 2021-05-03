import sys

if __name__ == "__main__":
    arr = list()
    for val in range(9):
        arr.append(int(input()))
    sorted_arr = list(reversed(sorted(arr))) #arr을 오름차순으로 정렬(sorted), 거꾸로 뒤집음(reversed)  즉 내림차순 객체반환, 그 객체를 리스트로 변환(list)
    max_val = sorted_arr[0]  # 최댓값

    for val in arr:
        if val == max_val:
            print(val)
            print(arr.index(val)+1)
            break
