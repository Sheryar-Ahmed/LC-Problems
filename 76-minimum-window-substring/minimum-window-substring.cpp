class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        // Frequency map for characters in t
        unordered_map<char, int> required;
        for (char c : t) {
            required[c]++;
        }

        // Frequency map for the current window
        unordered_map<char, int> window;
        int have = 0, need = required.size(); // `have` tracks how many characters satisfy the requirement
        int L = 0, minLen = INT_MAX;
        int minL = 0, minR = 0;

        for (int R = 0; R < s.size(); R++) {
            char c = s[R];
            window[c]++;

            // If this character satisfies the requirement
            if (required.find(c) != required.end() && window[c] == required[c]) {
                have++;
            }

            // Shrink the window from the left as much as possible
            while (have == need) {
                // Update the result if this window is smaller
                if (R - L + 1 < minLen) {
                    minLen = R - L + 1;
                    minL = L;
                    minR = R;
                }

                // Remove the leftmost character from the window
                char leftChar = s[L];
                window[leftChar]--;
                if (required.find(leftChar) != required.end() && window[leftChar] < required[leftChar]) {
                    have--;
                }
                L++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};