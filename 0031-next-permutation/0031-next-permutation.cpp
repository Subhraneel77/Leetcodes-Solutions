class Solution {
public:
    void nextPermutation(vector<int>& v) {
        if(v.size()==1) return;
        if(v.size()==2){
            swap(v[1], v[0]); return;
        }
        int i=v.size()-2;
        for(;i>=0;i--){
            if(v[i]<v[i+1]) break;
        }
        sort(v.begin()+i+1, v.end());
        if(i==-1) return;
        for(int j=i+1;j<v.size();j++){
            if(v[i]<v[j]) {
                swap(v[i], v[j]);
                return;
            }
        }
    }
};