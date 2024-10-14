class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        // Create a max heap using priority_queue
        std::priority_queue<int> pq;
        
        // Add elements to the priority queue
        for (int x : nums) {
            pq.push(x);
        }
        
        long long score = 0;
        
        // Process the queue while there are elements and k is greater than 0
        while (!pq.empty() && k > 0) {
            int x = pq.top();
            pq.pop();
            score += x;
            
            // Add the next element as the ceiling of x/3
            int newElement = static_cast<int>(std::ceil(x / 3.0));
            pq.push(newElement);
            
            k--;
        }
        
        return score;
    }
};
