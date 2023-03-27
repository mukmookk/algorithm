import sys
from collections import deque
N = int(input())
queue = deque()

for _ in range(N):
    s = sys.stdin.readline().strip().split()
    if len(s) > 1:
        queue.append(s[1])
    else:
        if s[0] == 'pop':
            if queue:
                print(queue.popleft())
            else:
                print(-1)
        elif s[0] == 'size':
            print(len(queue))
        elif s[0] == 'empty':
            print(1) if not len(queue) else print(0)
        elif s[0] == 'front':
            print(queue[0]) if len(queue) else print(-1)
        elif s[0] == 'back':
            print(queue[-1]) if len(queue) else print(-1)


