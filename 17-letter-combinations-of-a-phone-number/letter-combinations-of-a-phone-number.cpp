class Solution {
public:
    vector<string> result;

    void backtrack(int idx, string &digits, unordered_map<char, string> &mp, string &temp) {
        if (idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for (int i = 0; i < str.length(); i++) {
            // do
            temp.push_back(str[i]);
            // explore
            backtrack(idx + 1, digits, mp, temp);
            // backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
                
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        string temp = "";
        backtrack(0, digits, mp, temp);
        return result;
    }
};