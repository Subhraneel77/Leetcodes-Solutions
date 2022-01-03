class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int>trustedBy, trusted;

        int judge = -1;
        for(int i=1;i<=N;i++)
        {
            trustedBy[i]=0;
            trusted[i]=0;
        }
        for(int i=0;i<trust.size();i++)
        {
            trustedBy[trust[i][1]]++;
            trusted[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(trustedBy[i] == N-1 && trusted[i] == 0)
            {
                judge = i;
                break;
            }
        }
        return judge;
    }
};