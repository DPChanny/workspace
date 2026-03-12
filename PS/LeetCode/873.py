class Solution:
    def lenLongestFibSubseq(self, arr: list[int]) -> int:
        n = len(arr)
        max_len = 0

        dp = [[0] * n for _ in range(n)]

        val_to_idx = {val: idx for idx, val in enumerate(arr)}

        for k in range(n):
            for j in range(k):
                i = val_to_idx.get(arr[k] - arr[j], -1)

                if i + 1 > 0 and arr[k] - arr[j] < arr[j]:
                    dp[j][k] = dp[i][j] + 1
                else:
                    dp[j][k] = 2

                max_len = max(max_len, dp[j][k])

        return max_len if max_len > 2 else 0
