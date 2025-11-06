class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != '0') {
                    dfs(i, j, rows, cols, grid);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i, int j, int rows, int cols, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || j >= cols || i >= rows || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i + 1, j, rows, cols, grid);
        dfs(i, j + 1, rows, cols, grid);
        dfs(i - 1, j, rows, cols, grid);
        dfs(i, j - 1, rows, cols, grid);
    }
};