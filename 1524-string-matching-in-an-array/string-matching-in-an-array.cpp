class Solution {
public:
    bool isExist(const string& pattern, const string& text) {
        // Check if `pattern` is a substring of `text`
        return text.find(pattern) != string::npos;
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
