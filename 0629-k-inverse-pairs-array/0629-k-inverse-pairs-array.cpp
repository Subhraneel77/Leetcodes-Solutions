class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1);
        dp[0] = 1;
        for (int num = 0; num < n; num++) {
            int mx = n - num - 1;
            int window = 0;
            for (int i = 0; i <= mx; i++) {
                if (k - i < 0) break;
                window += dp[k - i];
                if (window >= MOD) window -= MOD;
            }
            for (int i = k; i >= 0; i--) {
                int curr = dp[i];
                dp[i] = window;
                window -= curr;
                if (window < 0) window += MOD;
                if (i - mx - 1 >= 0) {
                    window += dp[i - mx - 1];
                    if (window >= MOD) window -= MOD;
                }
            }
            
        }
        return dp[k];
    }
};