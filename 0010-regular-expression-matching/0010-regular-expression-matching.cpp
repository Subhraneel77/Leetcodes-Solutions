class Solution {
public:
bool helper(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    // Jai Shree Ram
    int n=s.size(),m=p.size();
    if(j==m){
        return (i==n);
    }
    if(dp[i][j]!=-1)return dp[i][j];
    bool nextStar=false;
    if(j+1<m&&p[j+1]=='*')
    nextStar=true;
    if(nextStar){
        bool a=false,b=false;
        // take
        if(i<n&&(s[i]==p[j]||p[j]=='.'))
        a=helper(i+1,j,s,p,dp);
        // not take
        b=helper(i,j+2,s,p,dp);
        return dp[i][j]= (a||b);
    }
    else{
        if(i<n&&(s[i]==p[j]||p[j]=='.'))
        return dp[i][j]= helper(i+1,j+1,s,p,dp);
    }
    return dp[i][j]= false;
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(0,0,s,p,dp);
    }
};
