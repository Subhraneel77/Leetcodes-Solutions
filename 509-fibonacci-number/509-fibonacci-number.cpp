class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int prev2 = 0, prev1 = 1, cur;
        for(int i=2;i<=n;i++){
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};