class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int s = (k-abs(endPos - startPos))/2;
        if(k < abs(endPos - startPos) || (k - abs(endPos - startPos)) % 2) return 0;
        else{
            vector<int> dp(s+1, 1);
            for(int i=0;i<k-s;i++) for(int j=1;j<s+1;j++) dp[j] = (dp[j] + dp[j-1]) % 1000000007;
            return dp[s];
        }
    }
    
};