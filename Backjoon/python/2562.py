lst = []

for i in range(9):
    lst.append(int(input()))

target = max(lst)
print(target)
print(lst.index(target))

# for i in range(9):
#     if lst[i] == target:
#         print(i)
#         break

