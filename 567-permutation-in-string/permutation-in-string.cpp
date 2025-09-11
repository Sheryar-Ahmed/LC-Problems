class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 =s1.size(); int len2 = s2.size();
        if(len2 < len1) return false;
        vector<int> freqs1(26, 0);
        vector<int> windowFreq(26, 0);
        for(int i=0; i < len1; i++){
            freqs1[s1[i]-'a']++;
            windowFreq[s2[i]-'a']++;
        }
        if(windowFreq == freqs1)  return true;
        for(int i=len1; i < len2; i++){
            windowFreq[s2[i]-'a']++;
            windowFreq[s2[i-len1]-'a']--;
            if(windowFreq == freqs1)  return true;
        }
        return false;
    }
};