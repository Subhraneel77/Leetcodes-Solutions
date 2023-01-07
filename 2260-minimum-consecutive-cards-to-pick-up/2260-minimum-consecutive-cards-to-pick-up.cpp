class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map <int, int> hash;
        int res = INT_MAX, flag=0;

        for(int i= 0; i<cards.size(); i++){

            if(hash.count(cards[i])){
                res = min(res, i-hash[cards[i]]+1 );
                flag =1;
            }
            hash[cards[i]] = i; 
        }

        return (flag ==0) ? -1 :res;
    }
};