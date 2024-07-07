class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        int val=0;
        vector<int> arr;
        for(int i=1;i<=n;i++)
        {
            arr.push_back(i);
        }
        for(int i=0;i<k-1;i++)
        {
            next_permutation(arr.begin(),arr.end());
        }
        for(int i=0;i<arr.size();i++)
        {
            val=val*10+arr[i];
        }
        ans=to_string(val);
        return ans;
        
    }
};