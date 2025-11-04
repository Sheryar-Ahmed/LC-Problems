class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        for (int i = 0; i < cols; i++) {
            dfs(0, i, rows, cols, heights, pacific);
        }
        for (int j = 0; j < rows; j++) {
            dfs(j, 0, rows, cols, heights, pacific);
        }

        for (int i = 0; i < cols; i++) {
            dfs(rows - 1, i, rows, cols, heights, atlantic);
        }
        for (int j = 0; j < rows; j++) {
            dfs(j, cols - 1, rows, cols, heights, atlantic);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>& heights,
             vector<vector<bool>>& ocean) {
        ocean[i][j] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= rows || y < 0 || y >= cols || ocean[x][y]) {
                continue;
            }
            if (heights[i][j] <= heights[x][y]) {
                dfs(x, y, rows, cols, heights, ocean);
            }
        }
    }
};