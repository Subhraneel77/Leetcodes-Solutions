class Solution {
public:
    double myPow(double x, int n) {
        double ans = x;
        bool neg = false;
        if(n < 0)
            neg = true;
        n = abs(n);
        
        if(n == 0)
            return 1;
        else if(n == 1){
            if(neg)
                return 1/x;
            return x;
        }
        else if(n == 2){
            if(neg)
                return 1/(x*x);
            return x * x;
        }
        
        ans = myPow(x, n/2);
        ans *= ans;
        if(n%2!=0){
            ans *= x;
        }
        if(neg)
            ans = 1 / ans;
        return ans;    
        
    }
};