class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        // Step 1: Build rank mapping
        for (int i = 0; i < order.size(); ++i) {
            rank[order[i] - 'a'] = i;
        }

        // Step 2: Compare adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!inCorrectOrder(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }

    bool inCorrectOrder(string &w1, string &w2, vector<int> &rank) {
        int len = min(w1.size(), w2.size());
        for (int i = 0; i < len; ++i) {
            if (w1[i] != w2[i]) {
                return rank[w1[i] - 'a'] < rank[w2[i] - 'a'];
            }
        }
        // If all equal so far, shorter word should come first
        return w1.size() <= w2.size();
    }
};
