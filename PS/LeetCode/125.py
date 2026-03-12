class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join([c.lower() for c in s if c.isalpha() or c.isdigit()])
        length = len(s)
        for i in range(length // 2):
            if s[i] != s[length - i - 1]:
                return False
        return True
