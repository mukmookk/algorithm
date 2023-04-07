def radix_sort(nums):
    RADIX = 10
    max_length = False
    digit = 1

    while not max_length:
        max_length = True
        buckets = [list() for _ in range(RADIX)]

        for num in nums:
            tmp = num // digit
            buckets[tmp % RADIX].append(num)
            if max_length and tmp > 0:
                max_length = False

        i = 0
        for j in range(RADIX):
            bucket = buckets[j]
            print(j, bucket)
            for num in bucket:
                nums[i] = num
                i += 1
        digit *= RADIX

    return nums

output = radix_sort([112, 122, 102, 122, 92])

print(output)