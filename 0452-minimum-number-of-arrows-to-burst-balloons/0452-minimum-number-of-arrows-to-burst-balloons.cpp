class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int l=points[0][0],r=points[0][1],ans=1;
        for(auto x : points){
            if(x[0]<=r){
                l=max(l,x[0]);
                r=min(r,x[1]);
            }else{
                ans++;
                l=x[0];
                r=x[1];
            }
        }
        return ans;
    }
};