class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int ans = 0,n = values.size();
        // store the max value of values[i]+i  tillthat index
        vector<int> dp(n); 
        dp[0] = values[0];
        for(int i = 1;i<n;i++)
        {
            // update the max value of values[i]+i till that index
            ans = max(ans,dp[i-1]+values[i]-i);
            // update answer
            dp[i]=max(dp[i-1],values[i]+i);
        }
        return ans;
    }
};