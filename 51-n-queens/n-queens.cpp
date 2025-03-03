class Solution {
public:
    int N;
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.')); //create a board forn=3 {"...", "...", "..."}
        solve( 0, board, n);
        return ans;
    }
    bool isValid(vector<string>& board, int row, int c){
        //check upward
        for(int i=row-1; i >=0; i--){
            if(board[i][c] == 'Q'){
                return false;
            }
        }
        //check diagonally upward right
        for(int i=row-1, j=c+1; i >=0 && j < N; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //check diagonally upward left
        for(int i=row-1, j=c-1; i >=0 && j >=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int row, vector<string>& board, int n){
        if(row >= n){
            ans.push_back(board);
            return;
        }
        for(int c=0; c < n; c++){
            if(isValid(board, row, c)){
                board[row][c] = 'Q'; //select
                solve(row+1, board, n); //explore
                board[row][c] = '.'; //reject 
                
            }
        }
    }
};