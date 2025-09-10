#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        unordered_map<char, int> window;
        int have = 0, need = freq.size();
        int left = 0, minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (freq.count(c) && window[c] == freq[c]) {
                have++;
            }

            // Shrink while valid
            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // shrink from left
                window[s[left]]--;
                if (freq.count(s[left]) && window[s[left]] < freq[s[left]]) {
                    have--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
