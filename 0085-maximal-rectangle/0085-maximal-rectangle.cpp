class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const unsigned short row=matrix.size(), col=matrix[0].size();
        if (row==1 && col==1) return matrix[0][0]=='1';
        vector<unsigned short> h(col+1);//height 
        int maxArea=0;

        for(int i=0; i<row; i++){
            vector<int> st={-1}; //stack will not be empty
            for (int j=0; j<=col; j++){
                // Count the successive '1's & store in h[j]
                h[j]=(j==col||matrix[i][j]=='0')?0:h[j]+1;

                // monotonic stack has at least element -1
                while(st.size()>1 && (j==col||h[j]<h[st.back()])){
                    const int m=st.back();
                    st.pop_back();
                    const int w=j-st.back()-1;
                    const int area=h[m]*w;
                    maxArea=max(maxArea, area);
                }
                st.push_back(j);
            }
        }
        return maxArea;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();