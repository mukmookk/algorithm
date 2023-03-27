N, K = map(int, input().split())

target = list(range(1, N + 1))
seq = []
idx = K - 1

while target:
    seq.append(target.pop(idx))
    N = N - 1 
    idx = idx - 1
    idx = (idx + K) % (N) if N > 0 else 0

formatted_list = "<" + ", ".join(str(x) for x in seq) + ">"
print(formatted_list)
