class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int mostFreq = 0;
        int maxFreq = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            window[s[right]]++;
            mostFreq = max(mostFreq, window[s[right]]);
            while ((right - left + 1) - mostFreq > k) {
                window[s[left]]--;
                left++;
            }
            maxFreq = max(maxFreq, right - left + 1);
            right++;
        }
        return maxFreq;
    }
};