class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Left is the shorter boundary
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left]; // water trapped above this bar

                left++;
            } else {
                // Right is the shorter boundary
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right]; // water trapped above this bar

                right--;
            }
        }

        return water;
    }
};
