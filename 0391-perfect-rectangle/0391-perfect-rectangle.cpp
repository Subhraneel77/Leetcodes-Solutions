class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mark;
        for(vector<int>& x:rectangles){
            mark[{x[0], x[1]}]++;
            mark[{x[0], x[3]}]--;
            mark[{x[2], x[1]}]--;
            mark[{x[2], x[3]}]++;
        }
        int n_mark=0;
        for(auto ptr=mark.begin();ptr!=mark.end();ptr++)
            if(ptr->second!=0){
                if(abs(ptr->second)!=1) return false;
                n_mark++;
            }
        return n_mark==4;
    }
};