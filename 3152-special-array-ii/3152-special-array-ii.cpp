class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> a(nums.size(), 0);
        vector<bool> v(nums.size() - 1, false);
        vector<bool> res;

        for (int i = 0; i < nums.size() - 1; i++) v[i] = (nums[i] % 2) == (nums[i + 1] % 2);

        for (int i = 1; i < nums.size(); ++i) a[i] = a[i - 1] + (nums.size() - 1 >= i - 1 && v[i - 1] ? 1 : 0);

        for (const auto& it : queries) {
            int to = it[1];
            int from = it[0];
            
            if (a[to] - a[from] <= 0) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};