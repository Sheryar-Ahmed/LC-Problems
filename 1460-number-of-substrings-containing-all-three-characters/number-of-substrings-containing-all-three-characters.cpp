class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> mp(3, 0); // 0-a, 1-b, 2-c;
        int result = 0;
        while(j < n) {
            mp[s[j]-'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result+= (n-j); // the total - upto j 
                // shrink the window
                mp[s[i]-'a']--;
                i++;
            }
            j++; // always increment;
        }
        return result;
    }
};