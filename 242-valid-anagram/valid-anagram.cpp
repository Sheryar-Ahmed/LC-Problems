class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> sf;
        for(auto &c: s){
            sf[c]++;
        }
        for(auto &c: t){
            if(sf.find(c) != sf.end()){
                sf[c]--;
                // remove the key also once it become zero
                if(sf[c] <= 0){
                    sf.erase(c);
                }
            }
        }
        return sf.size() == 0;
    }
};