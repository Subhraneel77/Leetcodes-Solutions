class Solution {
public:
    bool check(vector<int> need){
        for(int i = 0; i < need.size(); i++){
            if(need[i] < 0){
                return false;
            }
        }
        return true;
    }
    map<vector<int>, int> umap;
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(umap[needs] > 0){
            return umap[needs];
        }
        int minimum = 0;
        for(int i = 0; i < needs.size(); i++){
            minimum += needs[i] * price[i];
        }        
        for(auto spec : special){
            vector<int> need = needs;
            for(int i = 0; i < need.size(); i++){
                need[i] -= spec[i];
            }
            if(check(need)){
                minimum = min(minimum, spec[spec.size() - 1] + shoppingOffers(price, special, need));    
            }            
        }
        return umap[needs] = minimum;
    }
};