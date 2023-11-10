class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void build_adj(vector<vector<int>>& adjacentPairs){
        #pragma unroll
        for(auto& e: adjacentPairs){
            int v0=e[0], v1=e[1];
            if (adj.count(v0)) adj[v0].push_back(v1);
            else adj[v0]={v1};
            if (adj.count(v1)) adj[v1].push_back(v0);
            else adj[v1]={v0};
        }
    }
    vector<int> ans;
    void dfs(int i, int prev){
        ans.push_back(i);
        #pragma unroll
        for(int j: adj[i]){
            if (j==prev) continue;
            dfs(j, i);
        }

    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        build_adj(adjacentPairs);
        int root=INT_MAX;
        #pragma unroll
        for(auto& [i, vec]: adj){
            if (vec.size()==1){
                root=i;
                break;
            }
        }
        ans.reserve(adjacentPairs.size()+1);
        dfs(root, INT_MAX);
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();