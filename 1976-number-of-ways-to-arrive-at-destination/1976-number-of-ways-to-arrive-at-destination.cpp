class Solution {
public:
    int countPaths(int n, vector<vector<int>>& grid) {
        vector <vector <pair <long long, long long>>> graph(n+1);
        for(auto x: grid) { //creating adjacency list
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        long long INF = 1e15;
        long long MOD = 1e9 + 7;
        vector <long long> dp(n+1, 0);
        vector <long long> dist(n+1, INF);
        priority_queue <pair <long long, long long>> q; // maxHeap in c++
		// although we can use use minHeap in c++ by adding parameter to the maxHeap template
		// but I have inserted -1*val into the maxHeap so it worked fine as minHeap
		
        dist[0] = 0;
        dp[0] = 1; // initilize it to 1 since to reach 0 we have 1 way
        q.push({0, 0});
		
        while(q.size()) {
            long long node = q.top().second;
            long long nodeWt = -q.top().first;
            q.pop();

			/*
			what if we inserted min weight after some greater weight and we always pop min weight so it can be
			possible that some nodeWt (> dist[node]) is there in the queue that we haven't popped yet...
			hence we are continuing so that we don't traverse adjacency list of node again
			
			I have taken a graph as an example below the code.
			*/
            if(dist[node] < nodeWt) continue; // explained above
            for(auto key: graph[node]) {
                long long child = key.first;
                long long childWt = key.second;
                if(nodeWt + childWt == dist[child]) {
					// we are adding parent's dp value to child's dp 
                    dp[child] = (dp[child] + dp[node])%MOD;
                }
                if(nodeWt + childWt < dist[child]) {
                    dp[child] = dp[node]%MOD; // we are getting value of parent's dp
                    dist[child] = nodeWt + childWt;
                    q.push({-dist[child], child});
                }
            }
        }
        return dp[n-1];
    }
};