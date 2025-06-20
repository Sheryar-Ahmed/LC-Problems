class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Count characters in s1 and the first window in s2
        for (int i = 0; i < s1.size(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // If the first window matches, return true
        if (s1Count == s2Count) return true;

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); ++i) {
            s2Count[s2[i] - 'a']++;                     // add new character
            s2Count[s2[i - s1.size()] - 'a']--;         // remove old character
            
            if (s1Count == s2Count) return true;
        }

        return false;
    }
};
