class Solution {
public:
    bool isIsomorphic(string& s, string& t) {      
        int n = s.size();
        // Using size 256  for ASCII characters
        bitset<256> s_char=0, t_char=0;
        char st[256]={0};
        char ts[256]={0};
        
        for(int i = 0; i < n; i++) {
            char cs = s[i], ct = t[i];
            if(s_char[cs]==0 && t_char[ct]==0) {
                st[cs]=ct;
                ts[ct]=cs;
                s_char[cs]=1;
                t_char[ct]=1;
            }
            else {
                if(st[cs]!=ct || ts[ct]!=cs){
            //        cout<<"["<<i<<"] wrong mapping with cs="<<cs<<", ct="<<ct<<endl;
                    return 0;
                }
            }
        }
        return 1;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();