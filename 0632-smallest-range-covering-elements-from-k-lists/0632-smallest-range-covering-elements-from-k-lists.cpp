class Solution {
public:
    using int2=pair<int, int>;
    static inline bool less(int2& x, int2& y){
        auto [a, b]=x;
        auto [c, d]=y;
        if (b-a==d-c) return a<c;
        return b-a<d-c;
    }

    static vector<int> smallestRange(vector<vector<int>>& nums) {
        const int n=nums.size();
        vector<int2> A;
        for(int i=0; i<n; i++){
            for(int x: nums[i])
                A.emplace_back(x, i);
        }
        sort(A.begin(), A.end());
        int az=A.size(), cnt=0;
        vector<int> freq(n, 0);
        int2 min_range={0, INT_MAX};
        for(int l=0, r=0; r<az; r++){// slightly optimized
            int fR=++freq[A[r].second];
            if (fR==1) cnt++;
            while(cnt==n){
                int2 range={A[l].first, A[r].first};
                if (less(range, min_range)) min_range=range;
                int fL=--freq[A[l].second];
                if (fL==0) cnt--;
                l++;
            }
        }
        return {min_range.first, min_range.second};
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();