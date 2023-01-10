class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> rm;
        unordered_map<char, int> mz;
        
        for(auto x: ransomNote) rm[x]++;
        for(auto x: magazine) mz[x]++;
        
        for(auto x : rm)
        {
            if(mz[x.first]<x.second)
                return false;
        }
        return true;
     }
};