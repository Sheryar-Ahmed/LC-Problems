class Solution {
public:
    int maxArea(vector<int>& height) {
        // formula int minH = min(height[L], height[R]);
        // difference int R-L = 7 ;
        // maxA = max(maxA, diff*minH);
        int maxA = INT_MIN;
        int L = 0;
        int R = height.size() - 1;
        while (L < R) {
            int minH = min(height[L], height[R]);
            int diff = R - L;
            int area = minH * diff;
            maxA = max(maxA, area);
            if (height[L] < height[R]) {
                L++;
            } else {
                R--;
            }
        }
        return maxA;
    }
};