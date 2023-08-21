class Solution {
public:
    //Use sieve method to list a prime table
    vector<bool> isPrime;
    void sieve(int n){
        isPrime.assign(n+1, 1);
        isPrime[0]=isPrime[1]=0;
        int&& n_sqrt=int(sqrt(n));
        for(int&& i=2; i<=n_sqrt; i++){
            if (isPrime[i]){
                for(int j=i*i ; j<=n; j+=i)
                    isPrime[j]=0;
            }
        }
    }
    string repeatString(string& s , int k){
        string ans="";
        for(int i=0; i<k; i++){
            ans+=s;
        }
        return ans;
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if (n==1) return 0;
        sieve(n); 
        char s0=s[0];
        if (isPrime[n]){// only divisor 1 & n
            return string(n, s0)==s;
        }
        int sqrt_n=sqrt(n);
        for(int i=1; i<=sqrt_n; i++){
            if (n%i==0){
                if (s0==s[i]){
                    string ss=s.substr(0, i);
                    if (s==repeatString(ss, n/i)) 
                        return 1;
                }
                if (s[n/i]==s0){
                    string ss=s.substr(0, n/i);
                    if (s==repeatString(ss, i))
                        return 1;
                }              
            }
        }
        return 0;
    }
};