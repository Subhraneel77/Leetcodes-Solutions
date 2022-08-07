class Solution {
    int MOD = 1e9+7;
    int dfs(int n, char last, vector<vector<int>>& memo) {
        if(n == 0) return 1;
        
        if(memo[n][last] != -1) return memo[n][last];
        int total = 0;
        if(last == 'a') {
            total = (total + dfs(n-1, 'e', memo)) % MOD ;
        } else if(last == 'e') {
            total = (total + dfs(n-1, 'a', memo))% MOD;
            total = (total +  dfs(n-1, 'i', memo))% MOD;
        } else if(last == 'i') {
            total = (total +  dfs(n-1, 'a', memo))% MOD;
            total = (total +  dfs(n-1, 'e', memo))% MOD;
            total = (total +  dfs(n-1, 'o', memo))% MOD;
            total = (total +  dfs(n-1, 'u', memo))% MOD;
        } else if(last == 'o') {
            total = (total +  dfs(n-1, 'i', memo))% MOD;
            total = (total +  dfs(n-1, 'u', memo))% MOD;
        } else if(last == 'u') {
            total = (total +  dfs(n-1, 'a', memo))% MOD;
        } else {
            total = (total +  dfs(n-1, 'a', memo))% MOD;
            total = (total +  dfs(n-1, 'e', memo))% MOD;
            total = (total +  dfs(n-1, 'i', memo))% MOD;
            total = (total +  dfs(n-1, 'o', memo))% MOD;
            total = (total +  dfs(n-1, 'u', memo))% MOD;
        }
        
        return memo[n][last] = total;
    }
    
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> memo(n+1, vector<int>(130, -1));
        return dfs(n, '.', memo);
    }
};