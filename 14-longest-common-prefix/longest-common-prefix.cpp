class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans = "";
        
        for (int i = 0; i < strs[0].size(); i++) {
            char currentChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                // If the current string is shorter or character mismatches
                if (i >= strs[j].size() || strs[j][i] != currentChar) {
                    return ans;
                }
            }
            ans += currentChar;
        }
        
        return ans;
    }
};
