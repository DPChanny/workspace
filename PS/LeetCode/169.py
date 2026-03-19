class Solution:
    def majorityElement(self, nums):
        num_count = {}
        len_nums = len(nums)
        for num in nums:
            num_count[num] = num_count.get(num, 0) + 1
            if num_count[num] > len_nums // 2:
                return num
