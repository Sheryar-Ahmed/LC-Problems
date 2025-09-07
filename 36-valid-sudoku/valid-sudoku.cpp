class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> hash;
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
                    if (hash.find(rowCheck) != hash.end()) {
                        return false;
                    }
                    if (hash.find(colCheck) != hash.end()) {
                        return false;
                    }
                    if (hash.find(cubeCheck) != hash.end()) {
                        return false;
                    }
                    hash.insert(rowCheck);
                    hash.insert(colCheck);
                    hash.insert(cubeCheck);
                }
            }
        }
        return true;
    }
};