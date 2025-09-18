class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int number = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, rows, cols, grid, visited);
                    number++;
                }
            }
        }
        return number;
    }
    void dfs(int i, int j, int& rows, int& cols, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] ||
            grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        dfs(i + 1, j, rows, cols, grid, visited);
        dfs(i - 1, j, rows, cols, grid, visited);
        dfs(i, j + 1, rows, cols, grid, visited);
        dfs(i, j - 1, rows, cols, grid, visited);
    }
};