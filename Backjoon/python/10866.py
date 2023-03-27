from collections import deque
import sys

input = sys.stdin.readline
N = int(input())
deq = deque()

for _ in range(N):
    s = input().strip().split()
    if s[0] == 'push_front':
        deq.appendleft(s[1])
    elif s[0] == 'push_back':
        deq.append(s[1])
    elif s[0] == 'pop_front':
        print(deq.popleft()) if deq else print(-1)
    elif s[0] == 'pop_back':
        print(deq.pop()) if deq else print(-1)
    elif s[0] == 'size':
        print(len(deq))
    elif s[0] == 'empty':
        print(0) if len(deq) else print(1)
    elif s[0] == 'front':
        print(deq[0]) if len(deq) else print(-1)
    elif s[0] == 'back':
        print(deq[-1]) if len(deq) else print(-1)