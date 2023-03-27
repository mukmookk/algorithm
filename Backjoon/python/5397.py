from collections import deque
import sys

input = sys.stdin.readline

N = int(input())


for _ in range(N):
    
    basic_string = deque(input().strip())
    left = deque()
    right = deque()

    for s in basic_string:
        if s == '<':
            if left:
                right.appendleft(left.pop())
        elif s == '>':
            if right:
                left.append(right.popleft())
        elif s == '-':
            if left:
                left.pop()
        else:
            left.append(s)
    
    left = "".join(left)
    right = "".join(right)
    print(left + right)