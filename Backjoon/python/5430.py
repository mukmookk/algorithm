import sys
from collections import deque

T = int(input())
for _ in range(T):
    comm = deque(input())
    N = int(input())
    lst = deque(sys.stdin.readline().strip(" \n[]").split(','))
    if N == 0:
        lst = deque()
    error = 0
    rev_count = 0
    while comm:
        while comm and comm[0] == 'R':
            comm.popleft()
            rev_count = rev_count + 1
        if comm and comm[0] == 'D':
            if lst:
                if rev_count % 2:
                    lst.pop()
                else:
                    lst.popleft()
            else:
                print("error")
                error = 1
                break
            comm.popleft()
    if not error:
        if rev_count % 2:
            lst.reverse()
            print("[" + ",".join(lst) + "]")
        else:
            print("[" + ",".join(lst) + "]")




