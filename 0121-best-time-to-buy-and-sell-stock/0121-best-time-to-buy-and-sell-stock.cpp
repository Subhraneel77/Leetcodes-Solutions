class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = INT_MAX;
        int op = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < a){
                a = prices[i];
            }
            pist = prices[i] - a;
            if(op < pist){
                op = pist;
            }
        }
        return op;
    }
};