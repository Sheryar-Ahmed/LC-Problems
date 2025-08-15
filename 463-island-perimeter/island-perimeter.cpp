class Solution {
private:
vector<vector<int>> grid;
int rows;
int cols;
vector<vector<bool>> visited;
int dfs(int i, int j){
    if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0){
        return 1; // we have reached the water
    }
    if(visited[i][j]){
        return 0; // already visited don't count
    }
    visited[i][j] = true;
    return dfs(i+1, j)+dfs(i-1, j)+dfs(i, j+1)+dfs(i, j-1);
};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        this->rows = grid.size();
        this->cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i=0; i <rows; i++){
            for(int j=0; j < cols; j++){
                if(grid[i][j] == 1){
                    return dfs(i, j);
                }
            }
        }
        return 0;
    }
};