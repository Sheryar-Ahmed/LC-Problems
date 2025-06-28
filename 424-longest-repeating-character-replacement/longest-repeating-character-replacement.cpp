class Solution {
public:
    int characterReplacement(string s, int k) {
        // same elements ki longest substring konsi ha after perfomin k
        // operations on that substring
        vector<int> freq(26, 0); // 0--> freq
        int left = 0;
        int res = 0;
        int maxFreqCurrWindow = 0;
        for (int right = 0; right < s.size(); right++) {
            // frequency calculation
            freq[s[right]-'A']++; // 'A'-'A' = 0
            // expand
            maxFreqCurrWindow = max(maxFreqCurrWindow, freq[s[right]-'A']);
            // while invalid:
            if(right-left+1 - maxFreqCurrWindow > k) {
                freq[s[left]-'A']--;
                left++;
            }                
            //     shrink from left
            res = max(res, right-left+1);
            // update result
        }
        return res;
    }
};