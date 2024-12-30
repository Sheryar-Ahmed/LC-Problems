class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        // store each sorted string paris in the map
        for(auto &s: strs){
            auto temp = s;
            sort(temp.begin(), temp.end()); // it will sort the string and make the key
            mp[temp].push_back(s); // aet --> {all its paris will be here}
        }
        vector<vector<string>> ans;
        // we have made paris now we will just iterate over map
        for(auto &k: mp){
            ans.push_back(k.second);
        }
        return ans;
    }
};