class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()<2)
            return true;
        
        int level = 0, i=0, currentMax = 0, nextMax = 0;
        
        while(currentMax+1-i >0){       
            level++;
            for(;i<=currentMax;i++){    
                nextMax = max(nextMax, nums[i]+i);
                if(nextMax >=nums.size()-1)
                    return level;       
            }
            currentMax = nextMax;
        }
        return 0;
        
    }
};