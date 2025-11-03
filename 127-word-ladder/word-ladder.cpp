class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());
        if (!dic.count(endWord)) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int levels = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size-- && !q.empty()) {
                string word = q.front(); q.pop();
                for (int i = 0; i < word.size(); i++) {
                    string temp = word;
                    for(char s='a'; s <= 'z'; s++){
                        temp[i] = s;
                        if(temp == endWord){
                            return levels+1;
                        }
                        if(dic.count(temp)){
                            q.push(temp);
                            dic.erase(temp);
                        }
                    }
                }
            }
            levels++;
        }
        return 0;
    }
};