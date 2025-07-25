class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len2 < len1) return false;

        vector<int> freqs1(26, 0);
        vector<int> windowFreq(26, 0);

        // Count frequencies of characters in s1 and first window of s2
        for (int i = 0; i < len1; i++) {
            freqs1[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        // Check the first window
        if (freqs1 == windowFreq) return true;

        // Slide the window
        for (int i = len1; i < len2; i++) {
            // Add new character to the window
            windowFreq[s2[i] - 'a']++;
            // Remove the character that is left behind
            windowFreq[s2[i - len1] - 'a']--;

            // Check if the current window matches s1's frequencies
            if (freqs1 == windowFreq) return true;
        }

        return false;
    }
};
