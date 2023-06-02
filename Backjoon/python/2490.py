for _ in range(3):
    lst = list(map(int, input().split()))
    summed = sum(lst)
    
    if summed == 3:
        print("A")
    elif summed == 2:
        print("B")
    elif summed == 1:
        print("C")
    elif summed == 0:
        print("D")
    elif summed == 5:
        print("E")
