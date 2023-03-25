class Solution {
public:
    void dfs(int node,int& cnt,vector<int>& isVisited,vector<int> adj[]){
        isVisited[node]=1;
        cnt++;
        for(auto &i:adj[node]){
            if(isVisited[i]) continue;
            dfs(i,cnt,isVisited,adj);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> isVisited(n,0);
        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans=0,total_nodes=0;
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                int cnt=0;
                dfs(i,cnt,isVisited,adj);
                ans+=total_nodes*cnt;
                total_nodes+=cnt;
            }
        }
        return ans;
    }
};