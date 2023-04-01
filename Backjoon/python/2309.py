N = 9
lst = []
answer = []

for i in range(N):
    x = int(input())
    lst.append(x)    

summed = sum(lst)
lst = sorted(lst)

for i in range(len(lst)):
    for j in range(i + 1, len(lst)):
        if summed - lst[i] - lst[j] == 100:
            for k in range(9):
                if k != i and k != j:
                    print(lst[k])
            exit()
            

                    
# N = 9
# lst = []

# for _ in range(N):
#     lst.append(int(input()))

# summed = sum(lst)

# for i in range(len(lst)):
#     for j in range(i + 1, len(lst)):
#         if (summed - lst[i] - lst[j]) == 100:
#             lst.pop(i)
#             lst.pop(j-1)
#             break
#     if len(lst) == 7:
#         break
    
# lst.sort()

# print(*lst, sep="\n")

# import itertools

# numbers = [int(input()) for _ in range(9)]
# numbers.sort()
# for comb in itertools.combinations(numbers, 7):
#     if sum(comb) == 100:
#         print(*list(comb), sep="\n")
#         break


