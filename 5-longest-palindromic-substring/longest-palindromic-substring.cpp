class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            centerSolve(s, i, i, start, end);
            centerSolve(s, i, i+1, start, end);
        }
        return s.substr(start, end);
    }
    void centerSolve(string& s, int i, int j, int &start, int &end) {
        // now check if the current character expands and make the string
        // palindrome
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
        }
        // now compute string size j-i+1;
        if (j - i - 1 > end) {
            start = i + 1;
            end = j - i - 1;
        }
    }
};