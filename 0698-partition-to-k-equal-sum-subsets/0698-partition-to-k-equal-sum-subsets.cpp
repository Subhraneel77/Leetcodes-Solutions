class Solution {
public:
    
    vector<bool> vis;
    
    bool helper(vector<int>& nums, int i, int n, int k, int curr_sum, int target)
    {
        // base case
        
        if(k == 1)
            return true;
        
        if(i == n)
            return false;
        
        // we found one subset with sum == target, find other k - 1  subsets with sum == target
        
        if(curr_sum == target)
        {
            return helper(nums, 0, n, k - 1, 0, target);
        }
        
        for(int j = i; j < n; j++)
        {
            // if curr element is not taken and curr_sum + nums[j] is <= target, then take it and mark it visited
            
            if(vis[j] == false && curr_sum + nums[j] <= target)
            {
                vis[j] = true;
                
                curr_sum += nums[j];
                
                if(helper(nums, j + 1, n, k, curr_sum, target))
                    return true;
                
                // backtrack
                
                vis[j] = false;
                
                curr_sum -= nums[j];
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int sum = 0;
        
        // find the sum of the nums array
        
        for(auto x : nums)
        {
            sum += x;
        }
        
        // sum is odd
        
        if(sum % k)
            return false;
        
        // req_sum for each subset
        
        sum /= k;
        
        // take a visited array
        
        vis.assign(n, false);
        
        return helper(nums, 0, n, k, 0, sum);
    }
};