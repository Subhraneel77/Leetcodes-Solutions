class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
       string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        int i;
        string first=v[0], last=v[n-1];
        for (i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i])
            {
                return (ans);
            }
        ans=ans+first[i];
    }
    return ans;
    
}
};