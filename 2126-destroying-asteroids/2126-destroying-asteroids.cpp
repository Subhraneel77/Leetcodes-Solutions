class Solution {
public:

    bool asteroidsDestroyed(long long mass, vector<int>& ass) {
        
        sort(ass.begin(), ass.end());

        for(int i = 0; i < ass.size(); ++i)
        {
           if(mass < ass[i]) return false;
           
           else mass += ass[i];   
        }

        return true;
    }
};