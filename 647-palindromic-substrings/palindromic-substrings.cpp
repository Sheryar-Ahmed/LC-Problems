class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int l = i, r = j;
                while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }

                if (l >= r) {
                    count++;
                }
            }
        }

        return count;
    }
};