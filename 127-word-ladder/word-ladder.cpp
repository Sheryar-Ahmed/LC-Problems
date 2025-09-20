class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // make set of wordList for fast access
        unordered_set<string> dic(wordList.begin(), wordList.end());
        if (dic.find(endWord) == dic.end()) {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // intially the steps are 1 to reach beginWord
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            if (word == endWord)
                return steps;
            // else change one character.
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dic.find(temp) != dic.end() && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }
        return 0;
    }
};