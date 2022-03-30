class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// running a forloop till size of matrix
        for(int i  = 0; i<matrix.size(); ++i)
        {
		// nested for for ietrating each row element
            for(int j = 0; j<matrix[0].size(); ++j)
            {
				// if found return true
                if(matrix[i][j] == target)
                    return true;
            }
        }
		// after traversal if not found
		// return false
        return false;
    }
	
};