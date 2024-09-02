class Solution {
public:
    static int chalkReplacer(vector<int>& chalk, int k) {
        const int n=chalk.size();
        vector<long long> sum(n, chalk[0]);// prefix sum 0-indexed 
        for(int i=1; i<n; i++){
            sum[i]=sum[i-1]+chalk[i];
        //    cout<<i<<"->"<<sum[i]<<endl;
        }
        k%=sum[n-1];
    //    cout<<"k="<<k<<endl;

        return upper_bound(sum.begin(), sum.end(), k)-sum.begin();
    }
};




auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();