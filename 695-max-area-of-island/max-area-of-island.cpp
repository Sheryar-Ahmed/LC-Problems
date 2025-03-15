class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int& count) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        count++;
        DFS(grid, i-1, j, count);
        DFS(grid, i+1, j, count);
        DFS(grid, i, j-1, count);
        DFS(grid, i, j+1, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    int count = 0;
                    DFS(grid, i, j, count);
                    result = max(result, count);
                }
            }
        }
        return result;
    }
};