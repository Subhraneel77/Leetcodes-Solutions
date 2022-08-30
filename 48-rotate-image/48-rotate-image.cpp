class Solution {
public:

    void roro(vector<vector<int>>& matrix, int i, int k, int n){
        for (int j=0; j<k; j++){
            int t = matrix[i][i+j];
            matrix[i][i+j] = matrix[n-i-1-j][i];
            matrix[n-i-1-j][i] =  matrix[n-i-1][n-i-1-j];
            matrix[n-i-1][n-i-1-j] = matrix[i+j][n-i-1];
            matrix[i+j][n-i-1] = t;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int i = 0, n = matrix.size();
        int k = n-1;
        while (k>0){
            roro(matrix,i,k,n);
            i++;
            k-=2;
        }
        return;
    }
};