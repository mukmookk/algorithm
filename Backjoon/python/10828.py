import sys

input = sys.stdin.readline
stack = []

N = int(input().split()[0])
for _ in range(N):
    string = input().split()
    if len(string) > 1:
        stack.append(string[1])
    else:
        if string[0] == "top":
            if stack:
                print(stack[-1])
            else:
                print(-1)
        elif string[0] == "pop":
            if stack:
                print(stack.pop())
            else:
                print(-1)
        elif string[0] == "size":
            print(len(stack))
        elif string[0] == "empty":
            print(int(len(stack) == 0))