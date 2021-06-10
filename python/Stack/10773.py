import sys

# 정수 X를 스택에 넣는 연산이다.


def push(x):
    stack.append(x)

# 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.
# 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.


def pop():
    if(not stack):
        return 0
    else:
        return stack.pop()

# 스택에 들어있는 정수의 개수를 출력한다.


def size():
    return len(stack)

# 스택이 비어있으면 1, 아니면 0을 출력한다.


def empty():
    return 0 if stack else 1

# 스택의 가장 위에 있는 정수를 출력한다.
# 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.


def top():
    return stack[-1] if stack else -1


N = int(sys.stdin.readline().rstrip())
stack = []
_sum = 0
for _ in range(N):
    _input = N = int(sys.stdin.readline().rstrip())
    if(_input == 0):
        pop()
    else:
        push(_input)

_sum = sum(stack)
print(_sum)
