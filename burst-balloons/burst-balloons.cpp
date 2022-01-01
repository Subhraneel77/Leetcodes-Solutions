class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        // Get the number of balloons
        int n = nums.size();
        
        // Generate a new array by adding 1 on the left and right of nums[]
        vector<int> numsDP(n+2);
        numsDP[0] = numsDP[n+1] = 1;
        for(int i=1; i<=n; i++)
            numsDP[i] = nums[i-1];
        
        // Initialize entries of dp[][] with -1
        int dp[n+2][n+2];
        for(int i=0; i<n+2; i++)
            for(int j=0; j<n+2; j++)
                dp[i][j] = -1;
    
        // Iterate over different subarray sizes (s) in a bottom-up manner
        for(int s=2; s<=(n+2); s++)
        {
            for(int i=0; i<n+2-s+1; i++)
            {
                // Size 2 sub-arrays corespond to the base case (0 coins collected)
                if(s == 2)
                    dp[i][i+s-1] = 0;
                else // For other sub-arrays use the recusive formulation
                {
                    // Consider all possible choices of the last balloon to be burst
                    // And select the onee which maximises the number of coins collected
                    for(int j=i+1; j<(i+s-1); j++)
                    {
                        dp[i][i+s-1] = max(dp[i][i+s-1], dp[i][j] + dp[j][i+s-1] + numsDP[i]*numsDP[j]*numsDP[i+s-1]);
                    }
                }
            }
        }
        // Final answer is dp[0][n+1]
        return dp[0][n+1];
    }
};