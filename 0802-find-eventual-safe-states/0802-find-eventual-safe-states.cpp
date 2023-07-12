class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, int src, vector<bool> &visited, vector<bool> &dfsVisited){
        visited[src]=true;
        dfsVisited[src]=true;
        
        for(int i=0;i<graph[src].size();i++){
            int child=graph[src][i];
            if(visited[child]==false){
                if(dfs(graph,child,visited,dfsVisited)) return true;
            }else{
                if(dfsVisited[child]==true) return true;
            }
        }
        dfsVisited[src]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<bool> visited(n,false), dfsVisited(n,false);
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfs(graph,i,visited,dfsVisited)==false) ans.push_back(i);
        }
        
        return ans;
    }
};