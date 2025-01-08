class Solution {
public:
    // Function to check if s1 is both a prefix and suffix of s2
    bool isPrefixAndSuffix(const string& s1, const string& s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        
        if (len1 > len2) return false; // s1 can't be a prefix and suffix if it's longer than s2

        // Check prefix
        if (s2.substr(0, len1) != s1) return false;

        // Check suffix
        if (s2.substr(len2 - len1) != s1) return false;

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        // Iterate over all index pairs (i, j) where i < j
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};
