class Solution {
public:
	int solve(int i,int prev,vector<vector<int>>& pairs,int n,vector<vector<int>>& dp){
		if(i==n) return 0;

		if(dp[i][prev+1]!=-1) return dp[i][prev+1];

		int pick=-1e9;

		if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+solve(i+1,i,pairs,n,dp);
		int not_pick=solve(i+1,prev,pairs,n,dp);

		return dp[i][prev+1]=max(pick,not_pick);
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		int n=pairs.size();
		sort(pairs.begin(),pairs.end());
		vector<vector<int>> dp(n,vector<int>(n+1,-1));
		return solve(0,-1,pairs,n,dp);
	}
};