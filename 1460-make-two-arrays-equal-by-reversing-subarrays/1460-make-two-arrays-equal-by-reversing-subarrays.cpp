class Solution {
public:
    static bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001]={0}, n=target.size(), M=-1;
        for(int i=0; i<n; i++){
            int x=target[i], a=arr[i];
            freq[x]++;
            freq[a]--;
            M=max({M, x, a});
        }
        for(int x=1; x<=M; x++){
            if (freq[x]!=0) return 0;
        }
        return 1;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();