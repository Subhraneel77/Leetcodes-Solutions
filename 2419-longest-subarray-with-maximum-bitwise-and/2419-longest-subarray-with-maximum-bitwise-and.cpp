class Solution {
public:
    static int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int m=max_element(nums.begin(), nums.end())-nums.begin(); //Find index of max element
        int maxLen=0, x = nums[m];

        // Traverse from nums[m] on
        for (int i = m; i < n; i++) {
            int len = 0;

            // find contiguous subarray with maximum value
            while (i < n && nums[i] == x) {
                i++;
                len++;
            }
            // Update maxLen 
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();