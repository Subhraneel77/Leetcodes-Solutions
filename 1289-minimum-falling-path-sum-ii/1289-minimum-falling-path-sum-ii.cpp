class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int j = 0; j < m; ++j) {
            dp[0][j] = grid[0][j];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int temp = INT_MAX;

                for(int k = 0; k < m; ++k) {
                    if(k != j) {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for(int j = 0; j < m; ++j) {
            res = min(res, dp[n - 1][j]);
        }

        return res;
    }
};