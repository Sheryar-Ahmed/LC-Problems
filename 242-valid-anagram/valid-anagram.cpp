class Solution {
public:
    bool isAnagram(string s, string t) {
        // sorting || counting by hashmap
        // for(int i=0; i < s.size(); i++){
            
        // }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};