class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_count = 0;
        int row = strs.size();
        int column = strs[0].size();
        for (int j=0; j<column; j++)
        {
            for (int i=0; i<row-1;i++)
            {
                if(strs[i][j] > strs[i+1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
       return delete_count;
    }
};