class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k!=0){
            vector<int> ans = help(nums);
            int min = ans[0];
            int mi = ans[1];
            min *= multiplier;
            nums[mi] = min;
            k--;
        }
        return nums;
    }
    vector<int> help(vector<int>& nums){
        int n = nums.size();
        int min = nums[0],mi = 0;
        for(int i=1;i<n;i++){
            if(min > nums[i]){
                min = nums[i];
                mi = i;
            }
        }
        vector<int> arr = {min,mi};
        return arr;
    }
};