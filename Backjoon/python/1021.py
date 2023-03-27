from collections import deque
import sys

input = sys.stdin.readline

N, M = map(int, input().strip().split())
loc = map(int, input().split())
elem = deque(range(1, N + 1))
count = 0

for m in loc:
    target = elem.index(m)
    if elem[0] == m:
        elem.popleft()
        continue
    if len(elem) - target >= target:
        elem.rotate(-target)
        count += target
    else:
        elem.rotate(len(elem) - target)
        count += (len(elem) - target)
    elem.popleft()
print(count)