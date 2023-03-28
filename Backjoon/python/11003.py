from collections import deque

def solution(n, l, a):
    d = [0] * n
    dq = deque()
    for idx in range(n):
        while dq and dq[-1][1] > a[idx]:
            dq.pop()
        
        while dq and idx - dq[0][0] >= l:
            dq.popleft()
        
        dq.append((idx, a[idx]))
        d[idx] = dq[0][1]
    print(*d)

if __name__ == '__main__':
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    solution(n, l, a)
