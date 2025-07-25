class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> required;
        for (auto& x : t) {
            required[x]++;
        };

        unordered_map<char, int> window;
        int have = 0, need = required.size();
        int L = 0;
        // these are for substring
        int minLen = INT_MAX;
        int minL = 0;
        int minR = 0;

        for (int R = 0; R < s.size(); R++) {
            char c = s[R];
            window[c]++;
            if (required.find(c) != required.end() &&
                required[c] == window[c]) {
                have++; // aak element ki need puri hogi
            }
            // agar have or need equal hogy, we can shrink
            while (have == need) {
                char l = s[L];
                if (R - L + 1 < minLen) { // to get the min length
                    minLen = R - L + 1;
                    minL = L;
                    minR = R;
                }
                window[l]--;
                if (window.find(l) != window.end() && window[l] < required[l]) {
                    have--;
                }
                L++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};