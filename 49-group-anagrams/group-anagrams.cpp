class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() <= 1) return {strs};
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groupStr;
        for(auto &s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            groupStr[temp].push_back(s);
        };
        // now we will have strings that are grouped by same
        for(auto &v: groupStr){
            ans.push_back(v.second);
        }
        return ans;
    }
};