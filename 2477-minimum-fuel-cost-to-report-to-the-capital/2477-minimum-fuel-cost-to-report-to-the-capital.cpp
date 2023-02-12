class Solution {
typedef long long ll;
#define vi(x) vector<x>
#define pb push_back
public:
    vi(vi(ll))g;
    ll n;
    vi(bool)vis; /* return {number of cars in use, number of members arrived, number of empty seats, total liters of fuels consumed} */
    vi(ll) func(ll nd, const int&seats){
        ll avail=0, dist=0, members=1, cars=0;
        vis[nd]=1;
        for(ll child:g[nd]){
            if(!vis[child]){
                vi(ll)rec=func(child, seats);
                cars+=rec[0], members+=rec[1], avail+=rec[2], dist+=rec[0]+rec[3];
            }
        }
        vis[nd]=0;
        /* removinf unnecessary cars */
        ll waste=avail/seats;
        cars-=waste;
        avail-=waste*seats;
        if(avail>0){
            --avail;
        }
        else{
            ++cars, avail=seats-1;
        }
        
        return {cars, members, avail, dist};
    }
    long long minimumFuelCost(vector<vector<int>>&e, int seats) {
        n=e.size()+1;
        g.resize(n), vis.assign(n, 0);
        for(const auto&it:e){
            g[it[0]].pb(it[1]), g[it[1]].pb(it[0]);
        }
        return func(0, seats)[3];
    }
};