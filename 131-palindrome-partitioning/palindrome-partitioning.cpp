class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        backtrack(s, 0, par, pars);
        return pars;
    }

private:
    void backtrack(string& s, int start, vector<string>& par,
                   vector<vector<string>>& pars) {
        int n = s.length();
        if (start == n) {
            pars.push_back(par);
            return;
        }

        for (int i = start; i < n; i++) {
            // i is end of the string and start is start of the string so we are cutting 
            if (isPalindrome(s, start, i)) {
                par.push_back(s.substr(start, i - start + 1)); // cut the string
                backtrack(s, i + 1, par, pars); // increment the length of the string
                par.pop_back(); // backtrack
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};