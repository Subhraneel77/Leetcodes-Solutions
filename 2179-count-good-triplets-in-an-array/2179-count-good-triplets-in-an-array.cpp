#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),i;
        int a[n],b[n];
        for(i=0;i<n;i++){
            a[nums1[i]]=i;
        }
        ordered_set s;
        for(i=0;i<n;i++){
            int pos=a[nums2[i]];
            b[i]=s.order_of_key(pos+1);
            s.insert(pos);
        }
        ordered_set s2;
        s2.insert(a[nums2[n-1]]);
        long long ans=0;
        for(i=n-2;i;i--){
            int pos=a[nums2[i]];
            int x=(n-i-1)-s2.order_of_key(pos+1);
            ans+=((long long)x)*((long long)b[i]);
            s2.insert(pos);
        }
        return ans;
    }
};