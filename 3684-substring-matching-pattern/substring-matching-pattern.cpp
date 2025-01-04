class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*'); // Find the position of '*'
        string prefix = p.substr(0, star); // Get the prefix before '*'
        string suffix = p.substr(star + 1); // Get the suffix after '*'

        // Iterate through all possible substrings of s
        for (int start = 0; start < s.length(); ++start) {
            for (int end = start; end < s.length(); ++end) {
                string sub = s.substr(start, end - start + 1); // Get the substring of s
                // Check if the substring has enough length for prefix and suffix
                if (sub.length() >= prefix.length() + suffix.length()
                    && sub.substr(0, prefix.length()) == prefix
                    && sub.substr(sub.length() - suffix.length()) == suffix) {
                    return true;
                }
            }
        }

        return false;
    }
};
