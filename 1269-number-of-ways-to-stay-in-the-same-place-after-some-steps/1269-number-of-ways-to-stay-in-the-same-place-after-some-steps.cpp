class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1000000007;
        
        int maxPosition = std::min(steps / 2, arrLen - 1);
        
        // Create a 2D vector dp to store the number of ways to reach a specific position at each step.
        vector<vector<int>> dp(steps + 1, vector<int>(maxPosition + 1, 0));
        
        // Initialize the number of ways to stay at position 0 after 0 steps to 1.
        dp[0][0] = 1;
        
        // Loop through the number of steps.
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
                // Initialize the number of ways to stay at the current position with the number of ways to stay at the same position in the previous step.
                dp[i][j] = dp[i - 1][j];
                
                // If the current position is greater than 0, add the number of ways to reach it by moving left.
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                
                // If the current position is less than the maximum position, add the number of ways to reach it by moving right.
                if (j < maxPosition) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        
        // The final result is stored in dp[steps][0], representing the number of ways to reach the initial position after taking 'steps' steps.
        return dp[steps][0];
    }
};