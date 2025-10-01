class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true; // for an empty string the sub string is always exists
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        for(int i=1; i <= n; i++){
            for(int j=0; j < i; j++){
                if(dp[j] && dic.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};