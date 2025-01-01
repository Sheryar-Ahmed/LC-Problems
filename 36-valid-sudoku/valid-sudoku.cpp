class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> hash; // hash to store info

        for(int i=0; i < 9; i++){
            for(int j=0; j < 9; j++){
                char number = board[i][j];
            if(board[i][j] != '.'){
                string rowCheck = to_string(number) + "in row" + to_string(i);
                string colCheck = to_string(number) + "in col" + to_string(j);
                string cubeCheck = to_string(number) + "in cube" + to_string(i/3) 
                + to_string(j/3);
                if(hash.count(rowCheck) || hash.count(colCheck) || hash.count(cubeCheck)){
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