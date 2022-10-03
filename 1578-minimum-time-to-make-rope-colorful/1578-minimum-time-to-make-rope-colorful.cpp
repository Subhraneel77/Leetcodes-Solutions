class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int sum=neededTime[0];
        char prev=colors[0];
        int mxTime=neededTime[0];
        int ans=0;
        for(int i=1;i<colors.length();i++){
              if(colors[i]==prev){
                   sum+=neededTime[i];
                  mxTime=max(mxTime,neededTime[i]);
              }
            else{
                 ans+=(sum-mxTime);
                sum=neededTime[i];
               prev=colors[i];
                mxTime=neededTime[i];
               
            }
        }
        ans+=(sum-mxTime);
        return ans;
    }
};