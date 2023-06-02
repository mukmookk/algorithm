lst1 = [0, 0, 0, 0, 0, 0, 0]
award = 0
dices = list(map(int, input().split())) # "3 3 5" -> ["3", "3", "5"] -> [3, 3, 5]

for d in dices:
    lst1[d] = lst1[d] + 1

if 3 in lst1:
    award = 10000 + lst1.index(3)*1000
elif 2 in lst1:
    award  = 1000 + lst1.index(2)*100
else:
    for i in range(len(lst1) - 1, 0, -1):
        if lst1[i] == 1:
            award = i * 100
            break
    
print(award)
    