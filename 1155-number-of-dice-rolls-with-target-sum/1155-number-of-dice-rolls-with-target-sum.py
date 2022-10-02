class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [[0 for t in range(target + 1)] for i in range(n + 1)]
        dp[0][0] = 1
        M = 10**9 + 7
        for i in range(1, n + 1):
            s = dp[i - 1][0]
            for t in range(1, target + 1):
                if t > k:
                    s = (s - dp[i - 1][t - k - 1]) % M
                dp[i][t] = s
                s = (s + dp[i - 1][t]) % M
        return dp[n][target]