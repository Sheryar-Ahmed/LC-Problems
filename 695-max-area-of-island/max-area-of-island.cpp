class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        if(grid.empty()) return area;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0; i < rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j] == 1){
                    int curr = 0;
                    dfs(i, j, rows, cols, grid, curr);
                    area = max(area, curr);
                }
            }
        }

        return area;
    }
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>& grid, int& curr) {
        if (i < 0 || j < 0 || j >= cols || i >= rows || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        curr+=1;
        dfs(i + 1, j, rows, cols, grid, curr);
        dfs(i, j + 1, rows, cols, grid, curr);
        dfs(i - 1, j, rows, cols, grid, curr);
        dfs(i, j - 1, rows, cols, grid, curr);
    }
};