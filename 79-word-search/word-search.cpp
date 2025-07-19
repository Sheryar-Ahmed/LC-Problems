class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if (board[i][j] == word[0] && backtrack(board, i, j, word, 0)) {
                    return true;
                }     
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, int i, int j, const string& word, int ind){
        
        if(ind == word.length()){
            return true;
        }

        if(i < 0 || i>=board.size() || j <0 || j >=board[0].size() || board[i][j] != word[ind]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        bool found = (backtrack(board, i+1, j, word, ind+1) || 
                     backtrack(board, i-1, j, word, ind+1) || 
                     backtrack(board, i, j+1, word, ind+1) || 
                     backtrack(board, i, j-1, word, ind+1));
        board[i][j] = temp;
        return found; 
    }
};