class Solution:
    def longestCommonPrefix(self, strs):
        idx = 0
        prefix = ""
        while True:
            if idx >= len(strs[0]):
                return prefix
            prefix += strs[0][idx]
            for str in strs:
                if idx >= len(str) or str[idx] != prefix[-1]:
                    return prefix[:-1]
            idx += 1
