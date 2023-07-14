class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int d) {
        std::unordered_map<int, int> mp;
        int mx = 0;
        for (int i : arr) {
            mp[i] = mp[i - d] + 1;
            mx = std::max(mp[i], mx);
        }
        return mx;
    }
};