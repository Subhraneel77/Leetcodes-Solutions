class Solution {
public:
    int countSetBits(int n)
    {
        int count = 0;
        while(n > 0)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> bits;

        for(auto x : arr)
        {
            int count = countSetBits(x);
            bits.push_back({count,x});
        }

        sort(bits.begin(),bits.end());
        vector<int> ans;
        for(auto x : bits)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};