class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mi = INT_MAX;
        int count = 0;
        long long int sum = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mi = min(mi, abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    count++;
                }
                sum += abs(matrix[i][j]);
            }
        }
        if(count % 2 == 0){
            return sum;
        }
        return sum - 2 * (mi);
    }
};