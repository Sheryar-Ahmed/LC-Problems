class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        set<char> window;
        int l =0;
        int maxL = INT_MIN;
        for(int r=0; r < s.size(); r++){
            while(window.find(s[r]) != window.end()){ // shrink the windoww
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]); // expand the window
            // update results
            maxL = max(maxL, (int)window.size());
        }
        return maxL;
    }
};