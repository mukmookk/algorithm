import sys


N = int(input())
stack = []

for _ in range(N):
    value = int(input())
    if value == 0:
        stack.pop()
    else:
        stack.append(value)  
print(sum(stack))
    