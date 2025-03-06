class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        // Initialize the map with numbers from 1 to n^2
        for (int i = 1; i <= n * n; i++) {
            mp[i] = 0;
        }

        // Traverse the entire grid and count occurrences of each number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]]++;  // Increase the count for each number
            }
        }

        // Find the duplicate and missing number
        int duplicate = -1, missing = -1;
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] == 2) {
                duplicate = i;  // Number appearing twice
            }
            if (mp[i] == 0) {
                missing = i;  // Number missing from the grid
            }
        }

        return {duplicate, missing};
    }
};
