class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, n, 0,0, "");
        return ans;
    }
    void backtrack(vector<string>& ans, int n, int closeN, int openN, string curr){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        
        // case 1 opening paranthesis is smaller than closing
        if(openN < n){
            backtrack(ans, n, closeN, openN+1, curr+'(');
        }
        if(closeN < openN){
            backtrack(ans, n, closeN+1, openN, curr+')');
        }
    }
};