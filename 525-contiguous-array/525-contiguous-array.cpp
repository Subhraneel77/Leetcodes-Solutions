class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> mp;
        int maxy=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)  sum--;
            else sum++;
            if (sum==0)
            {
                maxy= i+1;
            }
            else
            {
                if (mp.find(sum)!=mp.end())
                {
                    maxy=max(maxy,i-mp[sum]);
                }
                else
                {
                    mp[sum]=i;
                }
            }
        }
        return maxy;
    }
};