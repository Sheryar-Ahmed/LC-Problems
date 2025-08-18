class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pac(rows, vector<int>(cols, 0));
        vector<vector<int>> atl(rows, vector<int>(cols, 0));

        // Directions
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // DFS lambda
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int r, int c, vector<vector<int>>& ocean) {
            ocean[r][c] = 1;
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
                if (ocean[nr][nc]) continue; // already visited
                if (heights[nr][nc] < heights[r][c]) continue; // must go uphill or flat
                dfs(nr, nc, ocean);
            }
        };

        // Pacific: top row + left col
        for (int c = 0; c < cols; c++) dfs(0, c, pac);
        for (int r = 0; r < rows; r++) dfs(r, 0, pac);

        // Atlantic: bottom row + right col
        for (int c = 0; c < cols; c++) dfs(rows-1, c, atl);
        for (int r = 0; r < rows; r++) dfs(r, cols-1, atl);

        // Collect results
        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
