# from collections import deque
# import sys

# input_ = sys.stdin.readline().rstrip()
# stack = deque()
# round_counter = 0
# edge_counter = 0

# for s in input_:
#     if s == '(':
#         stack.append('(')
#         round_counter += 1
#     elif s == '[':
#         stack.append('[')
#         round_counter += 1
#     elif s == ')':
#         if len(stack):
#             top = stack.pop()
#             if top != '(':
#                 print('0')
#                 break
#         else:
#             print('0')
#             break
#     elif s == ']':
#         if len(stack):
#             top = stack.pop()
#             if top != '[':
#                 print('0')
#                 break
#         else:
#             print('0')
#             break
