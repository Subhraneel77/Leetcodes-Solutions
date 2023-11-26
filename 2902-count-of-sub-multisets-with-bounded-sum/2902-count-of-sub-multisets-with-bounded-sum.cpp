class Solution {
    const int MOD = 1000000007; // Define a constant for modulo arithmetic.
    const int MAXN = 20000; // Define a constant for the maximum number of elements in the array.

    int dp[20005]; // Initialize an array to store dynamic programming values.

public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        for (int i = 0; i <= r; i++) {
            dp[i] = 0; // Initialize the DP array with zeros.
        }
        dp[0] = 1; // The base case for an empty set is 1.

        sort(nums.begin(), nums.end()); // Sort the input numbers in ascending order.
        reverse(nums.begin(), nums.end()); // Reverse the sorted array to start with the largest numbers.
        int sf = 0; // Initialize a variable to keep track of the sum of elements.

        // Handle leading zeros in the sorted array.
        while (nums.size() && nums.back() == 0) {
            dp[0]++;
            nums.pop_back(); // Remove leading zeros.
        }

        // Process the sorted array.
        while (nums.size()) {
            int tt = nums.back(); // Get the next unique number.
            int cn = 0; // Initialize a counter for this number.
            while (nums.size() && nums.back() == tt) {
                nums.pop_back();
                cn++; // Count the occurrences of the current number.
            }

            int chg = min(sf + tt * cn, r); // Calculate the change variable based on the sum so far.
            for (int i = chg; i >= tt; i--) {
                for (int j = 1; j <= cn && i - (j * tt) >= 0; j++) {
                    dp[i] += dp[i - j * tt]; // Calculate the number of subsets for the current sum.
                    if (dp[i] >= MOD) dp[i] -= MOD; // Apply modulo operation.
                }
            }

            sf += tt * cn; // Update the sum so far.
        }

        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += dp[i]; // Calculate the answer by summing the DP values within the given range.
            ans %= MOD; // Apply modulo operation to the final answer.
        }

        return ans;
    }
};
