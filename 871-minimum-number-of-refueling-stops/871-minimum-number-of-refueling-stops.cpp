class Solution {
public:
    int minRefuelStops(int target, int start_fuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        
        // declare a max. heap
        
        priority_queue<int> pq;
        
        int curr_dist = start_fuel;
        
        // count will store the no. of stops required
        
        int count = 0;
        
        int i = 0;
        
        // run the loop until curr_dist < target
        
        while(curr_dist < target)
        {
            // push the fuel into pq. until farthest position we can reach
            
            while(i < n && stations[i][0] <= curr_dist)
            {
                pq.push(stations[i][1]);
                
                i++;
            }
            
            // if pq is empty, then it is not possible to reach the target, return -1
            
            if(pq.empty())
                return -1;
            
            // add the max. fuel from pq
            
            curr_dist += pq.top();
            
            pq.pop();
            
            // increment the no. of stops
            
            count++;
        }
        
        return count;
    }
};