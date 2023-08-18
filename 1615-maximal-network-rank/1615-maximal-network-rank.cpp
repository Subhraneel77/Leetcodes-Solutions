class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        vector<int> deg(n, 0);
        for (auto& edge: roads){
            int v=edge[0], w=edge[1];
            deg[v]++;
            deg[w]++;
            adj[v].insert(w);
            adj[w].insert(v);
        }

        int max_rank=0;
        for(int i=0; i<n; i++){//Supposed that this graph is connected
            for(int j=0; j<i; j++){
                int rank=deg[i]+deg[j]-adj[i].count(j);
                max_rank=max(max_rank, rank);
            }
        }
        return max_rank;
    }
};