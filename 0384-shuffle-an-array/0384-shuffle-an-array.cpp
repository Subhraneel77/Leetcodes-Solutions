class Solution {
public:
    vector<int>v1, v2;
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
        int t1 = rand()%v1.size();
        int t2 = rand()%v1.size();
        swap(v2[t1],v2[t2]);
        return v2;
    }
};