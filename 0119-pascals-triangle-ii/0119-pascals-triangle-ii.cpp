class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int>> triangle;

        for (int i = 0; i <= rowIndex; i++) {
            std::vector<int> row(i + 1);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1;  // The first and last elements in each row are 1.
                } else {
                    int prevRow = i - 1;
                    int leftVal = triangle[prevRow][j - 1];
                    int rightVal = triangle[prevRow][j];
                    row[j] = leftVal + rightVal;  // Sum of the two numbers above.
                }
            }
            triangle.push_back(row);
        }

        return triangle[rowIndex];
    }
};