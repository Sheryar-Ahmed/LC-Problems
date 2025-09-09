class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int left = 0;
        int right = n-1;
        int water = 0;
        while(left < right){
            // if the left boundary is smaller and right is greater water will be stored according to the left boundary
            if(height[left] < height[right]){
                // if the max of left is greater than current left
                if(height[left] > leftMax){
                    leftMax = height[left];
                }else{
                    // calculate and add in the rain water
                    water += leftMax-height[left];
                }
                left++;
            }else{
                // what if the right boundary is smaller then the left
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    water += rightMax-height[right];
                }
                right--;
            }
        }
        return water;
    }
};