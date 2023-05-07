class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res(obstacles.size(), 1);
        vector<int> v;
        // Loop through each obstacle in the input vector
        for(int i=0; i<obstacles.size(); i++) {
            int tr = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin(); // Find the position of the first element in v that is greater than the current obstacle
            if (tr == v.size()) // If no such element exists in v, add the current obstacle to 
                v.push_back(obstacles[i]);
            else
                v[tr] = obstacles[i];
            
            res[i] = tr + 1;
        }
        
        // Return the result vector
        return res;
    }
};
