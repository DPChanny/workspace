class Solution:
    def singleNumber(self, nums) -> int:
        a = set()
        for num in nums:
            if num not in a:
                a.add(num)
            else:
                a.remove(num)
        return next(iter(a))
