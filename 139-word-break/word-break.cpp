class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        for(int i=1; i <= n; i++){ // substr exclude the last one that is upto n
            for(int j=0; j < i; j++){
                cout<<s.substr(j, i-j)<<endl;
                if(dp[j] && dic.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
            cout<<endl<<endl;
        }
        return dp[n];
    }
};