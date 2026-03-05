class Solution:
    def runningSum(self, nums):
        sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)
        return sums[1:]
