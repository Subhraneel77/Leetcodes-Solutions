class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = getDiameter(edges1);
        int d2 = getDiameter(edges2);
        return max(max(d1 - 1, d2 - 1), d1 / 2 + d2 / 2 + 1);
    }

private:
    int getDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> map;
        for (auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            map[i].push_back(j);
            map[j].push_back(i);
        }

        int res = 0;
        dfs(0, -1, map, res);

        return res;
    }

    int dfs(int node, int parent, unordered_map<int, vector<int>>& map, int& res) {
        int maxDepth = 1;
        for (int neighbor : map[node]) {
            if (neighbor == parent)
                continue;
            int depth = dfs(neighbor, node, map, res);
            res = max(res, maxDepth + depth);
            maxDepth = max(maxDepth, 1 + depth);
        }
        return maxDepth;
    }
};