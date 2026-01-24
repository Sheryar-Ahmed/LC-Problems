class Solution {
public:
    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c) {
        // out of bounds or not 'O'
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return;
        if (board[r][c] != 'O')
            return;

        // mark as safe
        board[r][c] = '#';

        // explore neighbors
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        rows = board.size();
        cols = board[0].size();

        // 1) Run DFS from border 'O's
        for (int r = 0; r < rows; r++) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }

        // 2) Flip surrounded regions
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';   // surrounded
                else if (board[r][c] == '#')
                    board[r][c] = 'O';   // safe
            }
        }
    }
};
