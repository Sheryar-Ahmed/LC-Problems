class NumMatrix {
private:
    vector<vector<int>> m;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Row-wise prefix sum
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (j > 0)
                    matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Column-wise prefix sum (on top of row-wise)
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        m = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = m[row2][col2];
        int left = (col1 > 0) ? m[row2][col1 - 1] : 0;
        int top = (row1 > 0) ? m[row1 - 1][col2] : 0;
        int overlap = (row1 > 0 && col1 > 0) ? m[row1 - 1][col1 - 1] : 0;

        return total - left - top + overlap;
    }
};
