import sys


def solve(a):
  return ord(a)


if __name__ == "__main__":
    num = input()
    str_in =input()

    total=0
    for val in str_in:
      total+=int(val)
    print(total)
''
