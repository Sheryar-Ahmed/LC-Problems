class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, n, "", ans);
        return ans;    
    }
    
    void backtrack(int openN, int closeN, int& n, string str, vector<string>& ans){
        if(openN == n && closeN == n){
            ans.push_back(str);
            return;
        }
        if(openN < n){
            backtrack(openN+1, closeN, n, str+'(', ans);
        }
        if(closeN < openN){
            backtrack(openN, closeN+1, n, str+')', ans);
        }
    }

};