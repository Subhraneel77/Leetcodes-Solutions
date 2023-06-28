class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back(make_pair(v, prob));
            graph[v].push_back(make_pair(u, prob));
        }
        
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;
        
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start));
        while (!pq.empty()) {
            pair<double, int> curr = pq.top();
            pq.pop();
            double currProb = curr.first;
            int currNode = curr.second;
            
            if (currNode == end) {
                return currProb;
            }
            
            for (pair<int, double> path : graph[currNode]) {
                int nextNode = path.first;
                double nextProb = currProb * path.second;
                
                if (nextProb > maxProb[nextNode]) {
                    maxProb[nextNode] = nextProb;
                    pq.push(make_pair(nextProb, nextNode));
                }
            }
        }
        
        return 0.0;
    }
};