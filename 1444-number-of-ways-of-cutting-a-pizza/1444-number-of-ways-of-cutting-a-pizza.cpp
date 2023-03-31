class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        // dp[k][r][c] represents the number of ways to cut the remaining pizza into k pieces
        // starting from row r and column c
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, -1)));
        // preSum[r][c] is the total number of apples in pizza[r:][c:]
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        // Compute preSum using dynamic programming, starting from the bottom-right corner of the pizza
        for (int r = m - 1; r >= 0; r--)
            for (int c = n - 1; c >= 0; c--)
                preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A' ? 1 : 0);
        // Start the recursive function dfs with initial parameters
        // m = number of rows, n = number of columns, k = number of pieces we need to cut the pizza into,
        // r = row index where we start cutting, c = column index where we start cutting
        return dfs(m, n, k-1, 0, 0, dp, preSum);
    }
    
    // Recursive function to compute the number of ways to cut the remaining pizza into k pieces
    int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum) {
        // If the remaining piece has no apple, then it is an invalid cut and we return 0
        if (preSum[r][c] == 0) return 0;
        // If we have found a valid way to cut the pizza into k pieces, then we return 1
        if (k == 0) return 1;
        // If the dp array already contains the number of ways to cut the remaining pizza into k pieces
        // starting from row r and column c, then we return the value from the dp array
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;
        // Cut the pizza horizontally at position nr if the upper piece contains at least one apple
        for (int nr = r + 1; nr < m; nr++) 
            if (preSum[r][c] - preSum[nr][c] > 0) 
                ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;
        // Cut the pizza vertically at position nc if the left piece contains at least one apple
        for (int nc = c + 1; nc < n; nc++) 
            if (preSum[r][c] - preSum[r][nc] > 0)
                ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007;
        // Memoize the result in the dp array and return the result
        return dp[k][r][c] = ans;
    }
};