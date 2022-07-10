class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) < 3:
            return min(cost)
        
        dp = [0]*(len(cost)+1)
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2, len(cost)):
            dp[i] = cost[i] + min(dp[i-1],dp[i-2])
        return min(dp[-2],dp[-3])