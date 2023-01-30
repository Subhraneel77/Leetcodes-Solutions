class Solution {
public:
    int memoized(int n, vector<int> &dp){
        if(n < 2)           return n;
        if(n == 2)          return 1;
        if(dp[n] != -1)     return dp[n];
        return dp[n] = memoized(n-1, dp) + memoized(n-2, dp) + memoized(n-3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return memoized(n, dp);
    }
};