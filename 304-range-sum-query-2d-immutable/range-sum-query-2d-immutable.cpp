class NumMatrix {
private:
    vector<vector<int>> m;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Add extra row and column to avoid bounds checks
        m = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                m[i][j] = matrix[i - 1][j - 1]
                        + m[i - 1][j]
                        + m[i][j - 1]
                        - m[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++; // shift for extra row/col

        return m[row2][col2]
             - m[row1 - 1][col2]
             - m[row2][col1 - 1]
             + m[row1 - 1][col1 - 1];
    }
};
