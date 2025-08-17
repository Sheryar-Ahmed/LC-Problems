class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges, count fresh
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Edge case: no fresh at all
        if (fresh == 0) return 0;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int sz = q.size();
            bool rotted = false;

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front(); q.pop();

                for (auto &d : dirs) {
                    int r = row + d[0];
                    int c = col + d[1];

                    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) 
                        continue;

                    grid[r][c] = 2;  // now rotten
                    fresh--;
                    rotted = true;
                    q.push({r, c});
                }
            }

            if (rotted) time++; // only increment if something rotted this round
        }

        return fresh == 0 ? time : -1;
    }
};
