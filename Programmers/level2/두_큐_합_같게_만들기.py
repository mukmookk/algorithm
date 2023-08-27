def solution(queue1, queue2):
    from collections import deque
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    sum_q = sum(queue1) + sum(queue2)
    if sum_q % 2:
        return -1

    count = 0
    target = sum_q // 2

    len_q = 2 * len(queue1 + queue2)
    sum1 = sum(queue1)

    for i in range(len_q):
        if sum1 < target:
            v = queue2.popleft()
            queue1.append(v)
            sum1 += v
        elif sum1 > target:
            v = queue1.popleft()
            queue2.append(v)
            sum1 -= v
        else:
            return count
        count += 1
    return -1