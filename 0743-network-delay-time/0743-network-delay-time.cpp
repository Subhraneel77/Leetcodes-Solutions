class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pii = pair<int,int>;
        vector<vector<pii>> adjList(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto& time : times) {
            int src = time[0]-1;
            int dst = time[1]-1;
            int wt = time[2];
            adjList[src].push_back({wt, dst});
        }
        vector<int> dists(n, INT_MAX);
        dists[k-1] = 0;
        pq.push({0, k-1});
        
        while(!pq.empty()) {
            auto [wt, src] = pq.top();
            pq.pop();
            if(dists[src] < wt) continue;
            auto& children = adjList[src];
            for(auto& [childWt, dst] : children) {
                int newWt = wt + childWt;
                if(newWt < dists[dst]) {
                    dists[dst] = newWt;
                    pq.push({newWt, dst});
                }
            }
        }
        int ans = 0;
        for(int x : dists) {
            if(x == INT_MAX) return -1;
            ans = max(ans, x);
        }
        
        return ans;
    }
};