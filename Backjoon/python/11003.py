import sys
from collections import deque

N, L = map(int, sys.stdin.readline().rstrip().split())
nums = deque(map(int, sys.stdin.readline().rstrip().split()))

leftmost = 0
window = deque([nums[0]])
min_elem = window[0]

for i in range(N):
    removed_data = -1
    if i - L + 1 >= 0:
        if leftmost <= i - L + 1:
            removed_data = window.popleft()
        leftmost = i - L + 1
    new_elem = nums[i]
    window.append(nums[i])

    if removed_data == min_elem:
        min_elem = min(window)
    elif new_elem < min_elem:
        min_elem = new_elem
print(min(window), end=" ")