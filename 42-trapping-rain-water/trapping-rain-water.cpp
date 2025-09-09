class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        // formula is hard to predict min(maxLeft, maxRight)-height[i];
        // for each position store its maxLeft, and maxRight
        int maxL = height[0];
        maxLeft[0] = 0;
        for (int i = 1; i < n; i++) {
            maxL = max(maxL, height[i - 1]);
            maxLeft[i] = maxL;
        }
        int maxR = height[n - 1];
        maxRight[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxR = max(maxR, height[i + 1]);
            maxRight[i] = maxR;
        }
        // for (auto& l : maxLeft) {
        //     cout << l << endl;
        // }
        // cout << endl;
        // for (auto& r : maxRight) {
        //     cout << r << endl;
        // }
        int water = 0;
        for (int i = 0; i < n; i++) {
            int contain = min(maxLeft[i], maxRight[i]) - height[i];
            if (contain >= 0) {
                water += contain;
            }
        }
        return water;
    }
};