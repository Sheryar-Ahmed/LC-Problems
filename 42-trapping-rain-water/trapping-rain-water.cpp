class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for(int i=0;i < n; i++){
            // we need to find the leftmax till our i
            int leftmax = height[i];
            int rightmax = height[i];
            for(int j=0; j < i; j++){
                leftmax = max(leftmax, height[j]); 
            }
            for(int k=i+1; k < n; k++) {
                rightmax = max(rightmax, height[k]);
            }
            ans+= min(leftmax, rightmax) - height[i];
        }
        return ans;
    }
};