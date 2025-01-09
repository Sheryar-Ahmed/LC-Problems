class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto w: words){
            if(w.substr(0, pref.size()) == pref){
                ans++;
            }
        }
        return ans;
    }
};