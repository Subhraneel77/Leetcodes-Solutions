class Solution {
public:

    vector<int> lisLength(vector<int>& v){
        vector<int> lis = {v[0]};
        vector<int> lisLen(v.size(), 1);

        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] > lis.back()){
                lis.push_back(v[i]);
            } else {
                int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[index] = v[i];
            }
            lisLen[i] = lis.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = lisLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLength(nums);
        reverse(lds.begin(), lds.end());

        int removals = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(lis[i] > 1 && lds[i] > 1){
                removals = min(removals, n + 1 - lis[i] - lds[i]);
            }
        }

        return removals;
    }
};