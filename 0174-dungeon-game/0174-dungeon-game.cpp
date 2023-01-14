class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        // declare a dp
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        
        // fill the dp table
        
        // dp[i][j] will store the minimum initial energy required from (i, j) to (n - 1, m - 1)
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(i == n - 1 && j == m - 1)
                {
                    dp[i][j] = grid[i][j] >= 0 ? 0 : grid[i][j];
                }
                else if(j == m - 1)
                {
                    dp[i][j] = grid[i][j] + dp[i + 1][j] >= 0 ? 0 : (grid[i][j] + dp[i + 1][j]);
                }
                else if(i == n - 1)
                {
                    dp[i][j] = grid[i][j] + dp[i][j + 1] >= 0 ? 0 : (grid[i][j] + dp[i][j + 1]);
                }
                else
                {
                    int right = grid[i][j] + dp[i][j + 1] >= 0 ? 0 : (grid[i][j] + dp[i][j + 1]);
                    
                    int down = grid[i][j] + dp[i + 1][j] >= 0 ? 0 : (grid[i][j] + dp[i + 1][j]);
                    
                    dp[i][j] = max(right, down);
                }
            }
        }
        
        return -dp[0][0] + 1;
    }
};