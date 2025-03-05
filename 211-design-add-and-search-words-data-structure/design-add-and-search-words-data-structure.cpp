class TrieNode {
public:
    bool isWord;
    TrieNode* childNode[26];
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isWord;

        char ch = word[index];
        if (ch == '.') {  // Wildcard case
            for (int i = 0; i < 26; i++) {
                if (dfs(node->childNode[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {  // Regular character case
            int idx = ch - 'a';
            return dfs(node->childNode[idx], word, index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawler->childNode[idx]) {
                crawler->childNode[idx] = new TrieNode();
            }
            crawler = crawler->childNode[idx];
        }
        crawler->isWord = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
