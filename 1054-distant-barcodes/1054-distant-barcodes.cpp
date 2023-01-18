class Solution {
public:

    vector<int> rearrangeBarcodes(vector<int>& bar) {

        if(bar.size() <= 1) return bar;

        unordered_map<int,int>mpp;

        for(auto &it : bar)
        {
           mpp[it]++;
        }

        priority_queue<pair<int,int>>vp;
        vector<int>res;

        for(auto &it : mpp)
        {
            vp.push({it.second,it.first});
        }

          while(vp.top().first > 0)
        {
            pair<int,int> p = vp.top();
            vp.pop();

            res.push_back(p.second);
            p.first--;

            pair<int,int> p2 = vp.top();
            vp.pop();

            if(p2.first > 0){
                res.push_back(p2.second);
                p2.first--;
            }

            vp.push(p);
            vp.push(p2);
        }

        return res;
    }
};

