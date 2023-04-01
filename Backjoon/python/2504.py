import sys

input_ = sys.stdin.readline().rstrip()
stack = []
cur_stacked = 1
answer = 0

for idx in range(len(input_)):
    if input_[idx] == '(':
        stack.append('(')
        cur_stacked *= 2
    elif input_[idx] == '[':
        stack.append('[')
        cur_stacked *= 3
    elif input_[idx] == ')':
        if not (stack and stack[-1] == '('):
            answer = 0
            break
        
        if input_[idx-1] == '(':
            answer += cur_stacked
        stack.pop()
        cur_stacked //= 2
    elif input_[idx] == ']':
        if not (stack and stack[-1] == '['):
            answer = 0
            break
        if input_[idx-1] == '[':
            answer += cur_stacked
        stack.pop()
        cur_stacked //= 3
if stack:
    answer = 0
    
print(answer)
        
        
