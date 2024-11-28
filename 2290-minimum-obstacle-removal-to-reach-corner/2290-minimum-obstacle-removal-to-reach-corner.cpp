class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        deque<pair<int, int>> dq{{0, 0}};
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        dist[0][0] = 0;
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                    int d = dist[x][y] + grid[nx][ny];
                    if (d < dist[nx][ny]) {
                        dist[nx][ny] = d;
                        grid[nx][ny] == 0 ? dq.push_front({nx, ny}) : dq.push_back({nx, ny});
                    }
                }
            }
        }
        return dist[r - 1][c - 1];
    }
};
auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
