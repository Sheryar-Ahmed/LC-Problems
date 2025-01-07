class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq(26, 0); // same approach as we did in characters
        vector<int> freqs1(26, 0);
        for(auto c: s1){
            freqs1[c-'a']++;
        };
        int L = 0;
        for(int R=0; R < s2.size(); R++){
            freq[s2[R]-'a']++; // as the letters are lowercase
            if(R-L+1 == s1.size()) {
                if(freq == freqs1) return true; // match found
                freq[s2[L]-'a']--;
                L++;
            }    
        } 
        return false;
    }
};