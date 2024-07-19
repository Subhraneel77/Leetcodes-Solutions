class Solution {
public:
    int dp[105][105];
    bool fdp(int i,int j,string &s1,string &s2, string &s3){
        int k=i+j;
        if(i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size()){
            if(s2[j]!=s3[k]) return false;
            else return dp[i][j]=fdp(i,j+1,s1,s2,s3);
        }
        if(j==s2.size()){
            if(s1[i]!=s3[k]) return false;
            else return dp[i][j]=fdp(i+1,j,s1,s2,s3);
        }
        if(s1[i]==s2[j]){
            if(s3[k]!=s1[i]) return false;
            else return dp[i][j]=fdp(i+1,j,s1,s2,s3)+fdp(i,j+1,s1,s2,s3);
        }
        else if(s1[i]==s3[k]) return dp[i][j]=fdp(i+1,j,s1,s2,s3);
        else if(s2[j]==s3[k]) return dp[i][j]=fdp(i,j+1,s1,s2,s3);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()+s2.size()!=s3.size()) return false;
        return fdp(0,0,s1,s2,s3);
        
    }
};