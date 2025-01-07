class Solution {
public:
bool isExist(const string& pattern, const string& text) {
    int m = pattern.size(), n = text.size();
    vector<int> lps(m, 0); // Longest prefix-suffix array

    // Build the LPS array
    for (int i = 1, len = 0; i < m;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    // Perform KMP search
    for (int i = 0, j = 0; i < n;) {
        if (pattern[j] == text[i]) {
            i++, j++;
        }
        if (j == m) {
            return true; // Found pattern in text
        }
        if (i < n && pattern[j] != text[i]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }

    return false;
}

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                // Avoid comparing the word with itself
                if (i != j && isExist(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break; // No need to check further for this word
                }
            }
        }

        return ans;
    }
};
