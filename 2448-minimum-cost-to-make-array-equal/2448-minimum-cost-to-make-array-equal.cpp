class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long mn = 0, mx = 1e6+2, mid,a,b,ans = LONG_LONG_MAX;
        int i, n = nums.size();
        while(mn <= mx){
            mid = (mx-mn)/2+mn;
            a = 0, b = 0;
            for(i = 0; i < n; i++){
                a += abs(mid-nums[i])*1LL*cost[i];
                b += abs(mid+1-nums[i])*1LL*cost[i];
            }
            ans = min({a,b,ans});
            if(b>a){
                mx = mid-1;
            }else{
                mn = mid+1;
            }
        }
        return ans;
    }
};
