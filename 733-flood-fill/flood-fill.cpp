class Solution {
private:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        // Out of bounds
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) {
            return;
        }
        // Stop if not the target color
        if (image[i][j] != oldColor) {
            return;
        }

        // Color the pixel
        image[i][j] = newColor;

        // Explore neighbors
        dfs(image, i + 1, j, newColor, oldColor);
        dfs(image, i - 1, j, newColor, oldColor);
        dfs(image, i, j + 1, newColor, oldColor);
        dfs(image, i, j - 1, newColor, oldColor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color) { // only flood if new color is different
            dfs(image, sr, sc, color, oldColor);
        }
        return image;
    }
};
