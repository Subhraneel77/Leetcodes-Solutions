class Solution {
public:
    vector<int> grayCode(int n) {
        // 1<<n gives us left shift of 1 by n, which is basically 2 to the power n
        vector<int> ans(1<<n);

        for (int i=0; i<(1<<n); i++) 
            // i >> 1 gives us right shift of i by 1, which is basically i/2
            ans[i] = i^(i>>1);
        return ans;
    }
};