class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        num_len = len(nums)
        left_sum = right_sum = 0
        for j in range(1, num_len):
            right_sum += nums[j]

        for i in range(num_len - 1):
            if right_sum == left_sum:
                return i
            left_sum += nums[i]
            right_sum -= nums[i + 1]
        if right_sum == left_sum:
            return num_len - 1
        return -1