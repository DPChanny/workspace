class Solution:
    def smallerNumbersThanCurrent(self, nums):
        size = len(nums)
        counts = []
        for i in range(0, size):
            count = 0
            for j in range(0, size):
                if i == j:
                    continue
                if nums[i] > nums[j]:
                    count += 1
            counts.append(count)
        return counts
