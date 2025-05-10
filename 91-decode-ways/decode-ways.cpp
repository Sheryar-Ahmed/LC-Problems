class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')
            return 0;

        int twoBack = 1; // dp[i-2]
        int oneBack = 1; // dp[i-1]

        for (int i = 1; i < s.size(); i++) {
            int curr = 0;

            if (s[i] != '0') {
                curr += oneBack;
            }

            int twoDigit = stoi(s.substr(i - 1, 2)); // i-1 because we are taking two digit in every case increasing order.
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += twoBack;
            }

            twoBack = oneBack;
            oneBack = curr;
        }

        return oneBack;
    }
};