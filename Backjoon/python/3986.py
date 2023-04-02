import sys

input = sys.stdin.readline

N = int(input().rstrip())
count  = 0

for _ in range(N):
    stack = []
    string = input().rstrip()
    for s in range(len(string)):
        if stack and stack[-1] == string[s]:
            stack.pop()
        else:
            stack.append(string[s])
    
    count = count + 1 if not stack else count

print(count)
