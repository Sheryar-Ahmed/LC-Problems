class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n + 1);

        dp[0] = 1; // there is one way to make an empty string
        dp[1] = 1; // for each element 1

        for (int i = 2; i <= n; i++) {
            int d = stoi(s.substr(i - 1, 1));
            int dd = stoi(s.substr(i - 2, 2));

            if (d >= 1 && d <= 9)
                dp[i] += dp[i - 1];
            if (dd >= 10 && dd <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};