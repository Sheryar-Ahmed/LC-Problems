class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (auto& c : t) {
            tFreq[c]++;
        }
        int left = 0;
        int right = 0;
        unordered_map<char, int> curr;
        int have = 0;
        int need = tFreq.size();
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.size()) {
            int c = s[right];
            curr[c]++;
            if (tFreq.count(c) && curr[c] == tFreq[c]) {
                have++;
            }
            // shrink
            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                curr[s[left]]--;
                if (tFreq.count(s[left]) && curr[s[left]] < tFreq[s[left]]) {
                    have--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};