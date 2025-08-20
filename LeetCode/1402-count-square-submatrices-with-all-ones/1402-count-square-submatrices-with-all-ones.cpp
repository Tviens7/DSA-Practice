class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = 1 + std::min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]});
                }
                count += matrix[i][j];
            }
        }
        return count;
    }
};