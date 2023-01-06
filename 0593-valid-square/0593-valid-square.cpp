class Solution {
public:
    double distance(vector<int> p1, vector<int> p2)
    {
        return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts = {p1, p2, p3, p4};
        set<double> st;
        for(int i = 0 ; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                double val = distance(pts[i], pts[j]);
                // if a normal value, then insert in cell
                if(val != 0)
                    st.insert(val);
                // if val == 0 means there are 2 same points
                else
                    return false;
            }
        }
        // there should be only 2 values, side distance or diagonal distance
        return st.size() == 2;
    }
};