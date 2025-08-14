class TrieNode {
public:
    bool isWord;
    TrieNode* childNode[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool dfs(TrieNode* root, string& word, int index){
        if(!root) return false;
        if(index == word.size()) return root->isWord;
        char ch = word[index];
        if(ch == '.'){
            for(int i=0; i< 26; i++){
                if(dfs(root->childNode[i], word, index+1)){
                    return true;
                }
            }
            return false;
        }else{
            int idx = ch-'a';
            return dfs(root->childNode[idx], word, index+1);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* crawler = root;
        for(auto s: word){
            int idx = s-'a';
            if(crawler->childNode[idx] == nullptr){
                crawler->childNode[idx] = new TrieNode();
            }
            crawler = crawler->childNode[idx];
        }
        crawler->isWord = true;
    }

    bool search(string word) {
        return dfs(root, word, 0); // root, currentword, starting index;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */