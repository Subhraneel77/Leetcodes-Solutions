class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array

        //////////START:Building Sparse Table////////////
        int m = 31 - __builtin_clz(n); // Determine the number of bits required to represent the length
        vector<vector<int>> dpmn(n, vector<int>(m + 1, INT_MAX)); // Sparse table for minimum values
        vector<vector<int>> dpmx(n, vector<int>(m + 1, INT_MIN)); // Sparse table for maximum values
        
        // Populate the initial values in the sparse tables
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m + 1; j++) {
                if (j == 0) {
                    dpmn[i][j] = nums[i];
                    dpmx[i][j] = nums[i];
                }
                else {
                    int i2 = i + (1 << (j - 1));
                    dpmn[i][j] = min(dpmn[i][j - 1], i2 < n ? dpmn[i2][j - 1] : INT_MAX);
                    dpmx[i][j] = max(dpmx[i][j - 1], i2 < n ? dpmx[i2][j - 1] : INT_MIN);
                }
            }
        }
         // Function to get the minimum value in a subarray
        auto getmin = [&](int l, int r) {
            int len = r - l + 1;
            int x = 31 - __builtin_clz(len);
            return min(dpmn[l][x], dpmn[r - (1 << x) + 1][x]);
        };
        
        // Function to get the maximum value in a subarray
        auto getmax = [&](int l, int r) {
            int len = r - l + 1;
            int x = 31 - __builtin_clz(len);
            return max(dpmx[l][x], dpmx[r - (1 << x) + 1][x]);
        };
        //////////END:Building Sparse Table////////////
        

        long long ans = 0;
        
        // Find the right index 'r' for each index 'i'
        for (int i = 0; i < n; i++) {

            int lo = i, hi = n - 1; // Binary search bounds
            
            // Perform binary search to find the rightmost index 'r'
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                
                int mn = getmin(i, mid); // Get the minimum value of the subarray
                int mx = getmax(i, mid); // Get the maximum value of the subarray
                
                if (mx - mn <= 2)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            // Handle the cases when lo and hi both can be rightmost            
            int r = lo;
            int mn = getmin(i, hi); 
            int mx = getmax(i, hi); 
            if (mx - mn <= 2)
                r = hi;
            
            ans += r - i + 1; // Add the count of valid subarrays starting from index 'i'
        }
        
        return ans; // Return the total count of valid subarrays
    }
};
