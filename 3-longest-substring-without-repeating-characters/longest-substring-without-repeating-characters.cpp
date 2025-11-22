class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int maxL = 0;

        while (right < s.size()) {
            // If duplicate found, shrink from left
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            // Now safe to insert
            window.insert(s[right]);
            maxL = max(maxL, right - left + 1);
            right++;
        }

        return maxL;
    }
};
