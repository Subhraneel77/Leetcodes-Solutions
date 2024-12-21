#define ll long long
class Solution {
public:
    int maxk(int node, int par, vector<vector<int>> &g,vector<ll> & subv,int k){
        int ans =1;
        for(auto v: g[node]){
            if(v==par){
                continue;
            }
            if(subv[v]%k==0){
                ans+=maxk(v,node,g,subv,k);
            }
            else{
                ans+=maxk(v,node,g,subv,k)-1;
            }
        }
        return ans;
        
    }
    ll dfs(int node, int par, vector<vector<int>> &g,vector<int> & values,vector<ll> &subv){
        // cout<<node<<"\n";
        ll ans =0;
        ll sum=values[node];
        for(auto v: g[node]){
            if(v==par){
                continue;
            }
            sum+=dfs(v,node,g,values,subv);

        }
        return subv[node]=sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(values.size());
        
        for(int i =0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<ll> subv(n,0);
        
        dfs(0,-1,g,values,subv);
        return maxk(0,-1,g,subv,k);
    }
};