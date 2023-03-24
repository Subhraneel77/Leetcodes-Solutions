class Solution {
public:
    int dfs(vector<vector<int>> &gr, vector<bool> &visited, int from) {
    auto change = 0;
    visited[from] = true;
    for (auto to : gr[from])
        if (!visited[abs(to)])
            change += dfs(gr, visited, abs(to)) + (to > 0);
    return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> gr(n);
        for (auto &c : connections) {
            gr[c[0]].push_back(c[1]);
            gr[c[1]].push_back(-c[0]);
        }
        return dfs(gr, vector<bool>(n) = {}, 0);
    }
};
