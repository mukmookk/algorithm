from collections import deque

n, m = map(int, input().split())
graph = []

for i in range(n):
    graph.append(list(map(int, input().split())))

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dfs(graph, a, b):
    queue = deque()
    queue.append((a, b))
    graph[a][b] = 0
    count = 1
    
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            