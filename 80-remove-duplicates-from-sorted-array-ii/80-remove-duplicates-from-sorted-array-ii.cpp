class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int k=1;
        int j=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==prev&&k<2)
            {
                nums[j]=prev;
                j++;
                k++;
            }
            else if(nums[i]!=prev)
            {
                nums[j]=nums[i];
                j++;
                k=1;
                prev=nums[i];
            }
        } 
        return j;
    }
};