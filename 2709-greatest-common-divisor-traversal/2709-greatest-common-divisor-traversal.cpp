#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int n;
    vector<int> prime;
    vector<vector<int>> commonFactor;
    vector<int> num_state;

    bitset<100001> sieved=0;
    
    void Sieve(int n){//TC: O(n log log n)
        sieved[0]=sieved[1]=1;
        int&& n_sqrt=int(sqrt(n));
        for(int i=2; i<=n_sqrt; i++){
            if (!sieved[i]){
                for(int j=i*i ; j<=n; j+=i)
                    sieved[j]=1;
            }
        }
        prime.reserve((int)log(n));
        for(int i=2; i<=n; i++)
            if (!sieved[i]) prime.push_back(i);
    }

    void build_commonFactor_path(auto& nums, int M) {
        num_state.assign(M+1, 0);
        commonFactor.resize(M+1, vector<int>());

        for (int x : nums)
            num_state[x] = 1;

        for (int p : prime) {// There are O(M/log(M)) primes 
            if (num_state[p] != 1)
                num_state[p] = -1;

            for (int i = p*2; i <= M; i += p) {
                if (num_state[i] == 1) {
                    commonFactor[i].push_back(p);
                    commonFactor[p].push_back(i);
                }
            }
        }
    }

    void dfs(int i, int& sz) {
        if (num_state[i]==1 && i!=1)
            sz++;
        num_state[i] = 2;

        for (int x : commonFactor[i]) {
            if (num_state[x] == 1 || num_state[x] == -1) {
                dfs(x, sz);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size()==1) return 1;
        int M=*max_element(nums.begin(), nums.end());
        int sqrtM=sqrt(M);
        Sieve(M);
        bitset<100001> S=0;
        for (int x : nums){
            if (x==1 ) return 0;
            S[x]=1;
        }
        nums.clear();
        for (int i=2; i<=M; i++)
            if(S[i]) nums.push_back(i);
        
        int n=nums.size();
        
        build_commonFactor_path(nums, M);
        for (int i : nums) {
            if (num_state[i] == 1) {
                int sz=0;
                dfs(i, sz);
                if (sz==n) return 1;
            }
        }
        return 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();