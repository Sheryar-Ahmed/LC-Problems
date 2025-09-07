class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> row;
        unordered_set<string> col;
        unordered_set<string> cube;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] != '.') {
                    char n = board[i][j] - '0';
                    string rowCheck =
                        to_string(i) + " row check in " + to_string(n);
                    string colCheck =
                        to_string(j) + "col check in" + to_string(n);
                    string cubeCheck = to_string(i / 3) + to_string(j / 3) +
                                       "cube check in" + to_string(n);
                    // row, col and cube checks;
                    if (row.find(rowCheck) != row.end()) {
                        return false;
                    }
                    if (col.find(colCheck) != col.end()) {
                        return false;
                    }
                    if (cube.find(cubeCheck) != cube.end()) {
                        return false;
                    }
                    row.insert(rowCheck);
                    col.insert(colCheck);
                    cube.insert(cubeCheck);
                }
            }
        }
        return true;
    }
};