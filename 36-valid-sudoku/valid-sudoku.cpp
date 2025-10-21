class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> m;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != '.') {
                    string row = "row" + to_string(i) + to_string(board[i][j]);
                    string col = "col" + to_string(j) + to_string(board[i][j]);
                    string box = "box" +
                                 to_string(i / 3) + to_string(j / 3) +
                                 to_string(board[i][j]);
                    if (m.count(row) || m.count(col) || m.count(box)) {
                        return false;
                    } else {
                        m.insert(row);
                        m.insert(col);
                        m.insert(box);
                    }
                }
            }
        }
        return true;
    }
};