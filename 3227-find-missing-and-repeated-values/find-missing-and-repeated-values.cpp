class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count(n * n + 1, 0); // Tracking occurrences of numbers from 1 to n²
        vector<int> ans(2, -1); // [duplicate, missing]

        // Traverse the grid and count occurrences
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        // Find the duplicate and missing numbers
        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 2) ans[0] = i; // Duplicate number
            if (count[i] == 0) ans[1] = i; // Missing number
        }

        return ans;
    }
};
