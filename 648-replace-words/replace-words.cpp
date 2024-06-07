#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    string getShortestPrefix(string word) {
        TrieNode* node = root;
        string prefix;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                break;
            }
            node = node->children[ch];
            prefix += ch;
            if (node->isEnd) {
                return prefix;
            }
        }
        return word; // if no prefix found, return the original word
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string root : dictionary) {
            trie.insert(root);
        }
        
        istringstream iss(sentence);
        string word;
        string result;
        
        while (iss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.getShortestPrefix(word);
        }
        
        return result;
    }
};
