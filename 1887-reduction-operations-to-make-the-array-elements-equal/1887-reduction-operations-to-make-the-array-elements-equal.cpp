class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int freq[50001]={0};
        int minN=50000, maxN=0;
        #pragma unroll
        for(int x: nums){
            freq[x]++;
            minN=min(minN, x);
            maxN=max(maxN, x);
        }
        int count=0, sum=0;
        #pragma unroll
        for(int x=maxN; x>minN; x--){
            if (freq[x] > 0) {
                sum+=freq[x];
                count+=sum;
            }
        }
        return count;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();