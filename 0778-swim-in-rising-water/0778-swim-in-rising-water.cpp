class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>time(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        time[0][0] = grid[0][0];
        int ans = 1e9;
     
        pq.push({time[0][0], {0,0}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
           
            
            for(int i = 0; i<4; i++)
            {
                int nrow = dr[i] + r;
                int ncol = dc[i] + c;
                
                if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && grid[nrow][ncol] < time[nrow][ncol])
                {
                    if(diff <  grid[nrow][ncol])
                    {
                        time[nrow][ncol] = grid[nrow][ncol];
                        pq.push({time[nrow][ncol], {nrow, ncol}});
                         
                    }
                    else if(diff < time[nrow][ncol])
                    {
                        time[nrow][ncol] = diff;
                        pq.push({time[nrow][ncol], {nrow, ncol}});
                    }  
                }
            }
            
        }
        return time[n-1][m-1];
    }
};