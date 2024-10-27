class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] = 1 + std::min({dp[i][j], dp[i + 1][j], dp[i][j + 1]});
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        
        return ans;
    }
};
