class Solution {
public:
    int uniquePaths(int m, int n) {
        // from each point i have two decisions either go down or left within bounds
        // for the first row and column there is 1 one way to reach after that we have to update our dp with the above and left value and at the end just return dp[n][m];
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int j =0; j < m; j++){
            dp[j][0] = 1;
        }
        for(int i=1; i < m; i++){
            for(int j=1; j < n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};