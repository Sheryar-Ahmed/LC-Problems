class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() < t.size()){
            return false;
        }else if(s.size() > t.size()){
            return false;
        }

        unordered_map<char, int> mp;
        for(auto &c: s){
            mp[c]++; // count the frequencies
        }

        for(auto &c: t){
            if(mp.find(c) == mp.end() || mp[c] == 0){ // if not found or found but the first string does not have it.
                return false;
            }
            mp[c]--; // decrement by 1 if found;
        }
        return true;
    }
};