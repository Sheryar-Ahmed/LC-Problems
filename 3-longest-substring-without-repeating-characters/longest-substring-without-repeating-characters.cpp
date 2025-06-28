class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int left = 0;
        set<char> window; // abc
        int res = INT_MIN;

        for (int right = 0; right < s.size(); right++) {
            while (window.find(s[right]) != window.end()) { // shrinking
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            // expand
            res = max(res, right - left + 1);
        }
        return res;
    }
};