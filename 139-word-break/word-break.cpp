class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // we can solve using dp dp[i] defines the string can be broken at i. we can create a dp of size s and check if all the string can be broken or not
        int n = s.size();
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        vector<bool> dp(n, false);
        dp[0] = true;// for empty string
        for(int i=1; i <= n; i++){
            for(int j=0; j < i; j++){
                if(dp[j] && dic.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break; // no further need to check
                }
            }
        }
        return dp[n];
    }
};