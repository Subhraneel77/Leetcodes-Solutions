class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX/2));
        for (int i = 0 ; i < n ; ++i) {
            dist[i][i] = 0;
        }
        
        for(const auto& e: edges){
            int s = e[0];
            int d = e[1];
            int c = e[2];
            dist[s][d] = c;
            dist[d][s] = c;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j]; 
                    }
                }
            }
        }
        
        int mini = INT_MAX;
        vector<int> counts(n,0);
        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(i == j) continue;
                
                if(dist[i][j] <= distanceThreshold){
                    ++count;
                }
            }
            mini = min(mini,count);
            counts[i] = count;
        }
        
        for(int i=n-1;i>= 0;i--){
            if(counts[i] == mini){
                return i;
            }
        }
        return -1;
    }
};