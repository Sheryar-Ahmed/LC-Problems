class Solution {
    void dfs(int i, int j, int rows, int cols, vector<vector<bool>>& reachable,
             vector<vector<int>>& heights) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                    reachable[i][j] = true;
        for (auto& dir : dirs) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni < 0 || ni >= rows || nj < 0 || nj >= cols) {
                continue;
            }
            if (reachable[ni][nj])
                continue;
            if (heights[ni][nj] < heights[i][j])
                continue;
            dfs(ni, nj, rows, cols, reachable, heights);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> atlantic(rows, vector<bool>(cols));
        vector<vector<bool>> pacific(rows, vector<bool>(cols));
        for (int i = 0; i < rows; i++)
            dfs(i, 0, rows, cols, pacific, heights);
        for (int j = 0; j < cols; j++)
            dfs(0, j, rows, cols, pacific, heights);

        for (int i = 0; i < rows; i++)
            dfs(i, cols - 1, rows, cols, atlantic, heights);
        for (int j = 0; j < cols; j++)
            dfs(rows - 1, j, rows, cols, atlantic, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};