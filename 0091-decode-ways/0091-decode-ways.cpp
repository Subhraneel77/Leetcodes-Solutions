class Solution {
public:
    int solve(string s,vector<int> &dp){
        if(s.size()==0) return 1;
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        if(dp[s.size()]!=-1) return dp[s.size()];
        
        int ans = solve(s.substr(1),dp) + (stoi(s.substr(0,2))<27?solve(s.substr(2),dp):0);
        return dp[s.size()] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,dp);
    }
};