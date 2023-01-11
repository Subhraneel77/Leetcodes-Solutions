class Solution {
public:
    int rev(int n)   //function to find reverse of a number
    {
        int res=0;
        while(n!=0)
        {
            res=res*10+n%10;
            n/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> um;     //to store the count of given formula
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i]-rev(nums[i]);        //given formula
            um[tmp]++;
            res=(res+um[tmp]-1)%1000000007;      //to count (i,j) pair indirectly
        }
        return res%1000000007;
    }
};
