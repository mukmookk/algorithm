from collections import deque
import sys

input = sys.stdin.readline

basic_string = list(input().strip())

left = deque(basic_string)
right = deque()

N = int(input().strip())
for _ in range(N):
    s = list(input().strip())
    if len(s) > 1:
        left.append(s[2])
    else:
        if s[0] == 'L':
            if left:
                right.appendleft(left.pop())
        elif s[0] == 'D':
                if right:
                    left.append(right.popleft())
        elif s[0] == 'B':
                if left:
                    left.pop()
left = "".join(left)
right = "".join(right)

print(left + right)