class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[count]!=nums[i]){
                count++;
                nums[count]=nums[i];
            }
            
        }
        return (count+1);
    }
};