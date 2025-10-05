class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& heights,
             vector<vector<bool>>& ocean) {
        ocean[i][j] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || ocean[x][y]) {
                continue;
            }
            if (heights[i][j] <= heights[x][y]) {
                dfs(x, y, m, n, heights, ocean);
            }
        }
    };
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        // for pacific top row and left most col
        for (int i = 0; i < n; i++) {
            dfs(0, i, m, n, heights, pacific);
        }
        for (int j = 0; j < m; j++) {
            dfs(j, 0, m, n, heights, pacific);
        }
        // for atlantic right most and right most bottom
        for (int i = 0; i < m; i++) {
            dfs(i, n-1, m, n, heights, atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(m-1, j, m, n, heights, atlantic);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};