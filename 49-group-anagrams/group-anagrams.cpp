class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // need to create hashmap with sorting the word and link the matching one's with it
        // just iterate over the hashmap and based on the key index which is sorted just add a vector and store the results and return them
        unordered_map<string, vector<string>> mp;
        for(auto str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>> result;
        for(auto key: mp){
            result.push_back(key.second);
        }
        return result;
    }
};