class TrieNode {
    public:
        bool isWord;
        TrieNode* childNode[26];
        TrieNode() {
            for(int i=0; i < 26; i++) {
                childNode[i] = NULL;
            }
            isWord = false;
        }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(auto ch: word){
            int idx = ch-'a'; // to get the index
            if(crawler->childNode[idx] == NULL){
                crawler->childNode[idx] = new TrieNode();
            }
            // move the crawler to the next
            crawler = crawler->childNode[idx];
        }
        crawler->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(auto ch: word){
            int idx = ch-'a'; // to get the index
            if(crawler->childNode[idx] == NULL){
                return false;
            }
            // move the crawler to the next
            crawler = crawler->childNode[idx];
        }
        return crawler->isWord;
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* crawler = root;
        for(auto ch: prefix){
            int idx = ch-'a'; // to get the index
            if(crawler->childNode[idx] == NULL){
                return false;
            }
            // move the crawler to the next
            crawler = crawler->childNode[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */