class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        
        queue<pair<int, int>> q;
        int freshCount = 0; // Count of fresh oranges
        
        // Initialize the queue and count the fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Perform BFS
        while(!q.empty() && freshCount > 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();
                
                for(auto dir : directions) {
                    int newRow = current.first + dir.first;
                    int newCol = current.second + dir.second;
                    
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                        grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        freshCount--;
                        q.push({newRow, newCol});
                    }
                }
            }
            if(!q.empty()) minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};