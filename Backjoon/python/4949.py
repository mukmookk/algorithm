# backjoon 4949
import sys

while True:
    string = sys.stdin.readline().rstrip()
    if string == ".":
        break
    stack = []
    for s in string:
        if s == "[":
            stack.append("[")
        elif s == "(":
            stack.append("(")
        elif s == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                print("no")
                break
        elif s == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                print("no")
                break
        elif s == ".":
            if stack:
                print("no")
            else:
                print("yes")
