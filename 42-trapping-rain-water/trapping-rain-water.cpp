class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        int maxL = height[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = maxL;
            maxL = max(maxL, height[i]);
        }
        int maxR = height[n-1];
        for (int i = n-1; i >= 0; i--) {
            maxRight[i] = maxR;
            maxR = max(maxR, height[i]);
        }
        int water = 0;
        for(int i=0; i < n; i++){
            int contain = min(maxLeft[i], maxRight[i]) - height[i];
            if(contain >= 0){
                water+=contain;
            }
        }
        return water;
    }
};