class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);               // Track columns
        vector<bool> diag1(2 * n - 1, false);       // ↘ diagonals (row - col + n - 1)
        vector<bool> diag2(2 * n - 1, false);       // ↙ diagonals (row + col)
        int count = 0;
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, cols, diag1, diag2, count);

            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};
