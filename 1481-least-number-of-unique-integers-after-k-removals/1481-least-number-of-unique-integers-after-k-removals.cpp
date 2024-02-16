class Solution {
public:
    using int2=pair<int, int>;
    struct cmp{
        bool operator()(int2& x, int2& y){
            return x.second>y.second;
        }
    };
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int prev=0;
        vector<int2> freq;
        for(int x: arr){
            if (x!=prev) {
                freq.emplace_back(x, 1);
                prev=x;
            }
            else freq.back().second++;
        }
        priority_queue<int2, vector<int2>, cmp> pq(freq.begin(), freq.end());
        while(k>0 && !pq.empty()){
            auto [x, f]=pq.top();//the min freq[x] on the top
            pq.pop();
            k-=f;
        }
        int sz=pq.size();
    //    cout<<sz<<endl;
        return k==0?sz:sz+1;
    }
};
