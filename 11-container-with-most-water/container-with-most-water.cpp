class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int maxArea = INT_MIN;
        while (L < R) {
            if (height[L] < height[R]) {
                maxArea = max(maxArea, height[L] * (R - L)); L++;
            } else {
                maxArea = max(maxArea, height[R] * (R - L)); R--;
            }
        }
        return maxArea;
    }
};