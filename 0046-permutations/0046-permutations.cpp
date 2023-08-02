class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int> nums , int i){
        if(i == nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i] , nums[j]);
            recur(nums , i + 1);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        recur(nums , 0);
        return ans;
    }
};