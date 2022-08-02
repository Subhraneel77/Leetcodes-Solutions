class Solution {
public:
    int jump(vector<int>& ar) {


        int n = ar.size();

        int j = 0, mx = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            mx = max(mx, ar[i] + i);
            if (i == j)
            {
                cnt++; j = mx;
            }
        }
        return cnt;

    }
};