class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
                return;
            }
            grid[i][j] = 0;
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || n-1 == i || m-1 == j) && grid[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s += grid[i][j];
            }
        }
        return s;
    }
};