class Solution {
public:
    using int2=pair<int, int>;
    static vector<int> arrayRankTransform(vector<int>& arr) {
        const int n=arr.size();
        vector<int2> arrIdx(n);
        for(int i=0; int x: arr){
            arrIdx[i]={x, i};
            i++;
        }
        sort(arrIdx.begin(), arrIdx.end());
        vector<int> ans(n);
        int prev=INT_MIN, curr=0;
        for(auto& [x, i]: arrIdx){
            if (x>prev) curr++;
            ans[i]=curr;
            prev=x;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();