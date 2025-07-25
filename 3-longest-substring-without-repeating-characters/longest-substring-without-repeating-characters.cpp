class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int L=0;
        unordered_set<char> window;
        for(int R=0; R < s.size(); R++){
            while(window.find(s[R]) != window.end()){
                window.erase(s[L]);
                L++;
            }
            window.insert(s[R]);
            int le = window.size();
            res = max(res, le);
        }
        return res;
    }
};