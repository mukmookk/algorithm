import sys
from collections import deque
input = sys.stdin.readline

string = input().rstrip()
stack = deque()
stacked = 0
answer = 0
prev = 0

for s in string:
    if "(" == s:
        stacked = stacked + 1
        stack.append(s)
    elif ")" == s:
        stack.pop()
        stacked -= 1
        if prev == '(':
            answer += stacked
        else:
            answer += 1
    prev = s
print(answer)
            
        
            

            
        