class TrieNode{
public:
    TrieNode* childnode[26];
    bool isword;
    TrieNode(){
    for(int i=0; i < 26; i++){
        childnode[i] = NULL;
    }
    isword = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            insert(words[i]);
        };
        vector<string> res;
        TrieNode* node = root;
        rows = board.size();
        cols = board[0].size();
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
                dfs(board, rows, cols, i, j, node,"", res);
            }
        }
        return res;
    }
private:
    int rows;
    int cols;
    TrieNode* root = new TrieNode();
    
    void insert(string word){
        TrieNode* node = root;
        for(int i=0; i < word.size(); i++){
            int curr = word[i]-'a';
            if(node->childnode[curr] == NULL){
                node->childnode[curr] = new TrieNode();
            }
            node = node->childnode[curr];
        }
        node->isword = true;
    }

    void dfs(vector<vector<char>>& board, int rows, int cols, int i, int j, 
    TrieNode* node, string word, vector<string> &res){
        if(i < 0 || i >= rows || j < 0 || j >=cols || board[i][j] == '#'){
            return;
        }
        
        char c = board[i][j];
        if (node->childnode[c-'a'] == NULL) {
            return;
        }
        node = node->childnode[c-'a'];
        word+=board[i][j];
        if(node->isword){
            res.push_back(word);
            node->isword = false;
        }
        
        board[i][j] = '#';
        
        dfs(board, rows, cols, i-1, j, node, word, res);
        dfs(board, rows, cols, i+1, j, node, word, res);
        dfs(board, rows, cols, i, j-1, node, word, res);
        dfs(board, rows, cols, i, j+1, node, word, res);

        board[i][j] = c;
    }
};