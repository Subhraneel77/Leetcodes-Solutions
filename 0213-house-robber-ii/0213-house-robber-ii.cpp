class Solution {
private:
    
    int solveSO(vector<int> &nums, int n)
    {
        int prev2=0;
        int prev1=nums[0];
        int curr=0;

        for(int i=1;i<=n;i++)
        {
            int include = prev2+ nums[i];
            int exclude=prev1;
            curr=max(include, exclude);

            prev2=prev1;
            prev1=curr;
        }
        
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> first(n),last(n);

        for(int i = 0 ; i < n ; i++){
            if(i != n-1){
                first.push_back(nums[i]);
            }

            if(i != 0){
                last.push_back(nums[i]);
            }
        }

        return max (solveSO(first, first.size()), solveSO(last, last.size())); 

    }
};