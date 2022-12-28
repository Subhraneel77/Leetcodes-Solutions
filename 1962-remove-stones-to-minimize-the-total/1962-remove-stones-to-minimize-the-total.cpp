class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i = 0;i < piles.size();i++){
            pq.push(piles[i]);
        }
        while(k > 0){
            int temp = pq.top();
            pq.pop();
            if(temp % 2 != 0){
                temp++;
            }
            temp /= 2;
            pq.push(temp);
            k--;
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};