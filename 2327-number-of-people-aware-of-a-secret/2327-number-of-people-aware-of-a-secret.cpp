class Solution {
private:
//https://www.youtube.com/watch?v=V7QVZY84KQ8&ab_channel=CodingDecoded
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>persons(n+1,0);
        persons[1] = 1; //persons[i] => persons sharing the secret at day i
        long long numberOfPeopleSharingSecret = 0;
        for(int i=2;i<=n;i++){
            if(i - delay >= 0) 
                numberOfPeopleSharingSecret = (numberOfPeopleSharingSecret + persons[i-delay])%mod;
            if(i - forget >= 0) 
                numberOfPeopleSharingSecret = (numberOfPeopleSharingSecret - persons[i- forget] + mod)%mod;
            
            persons[i] = numberOfPeopleSharingSecret;
        }

        long long ans = 0;//add all persons who are not forgotten the secret
        for(int i=n-forget+1;i<=n;i++){
            ans = (ans + persons[i]) % mod;
        }

        return ans;
    }
};