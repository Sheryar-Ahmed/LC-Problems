class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 1) return 0;
        // maintain a window of set
        unordered_set<char> window;
        int left = 0;
        int right = 0;
        int len = 0;
        while(right < s.size()){
            while(right < s.size() && window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]); // expand it // abc
            len = max(len, right-left+1);
            right++; // 3
        }
        return len;
    }
};