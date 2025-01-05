class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }
        
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n-1;
        int leftmax = height[l], rightmax = height[r];
        while(l < r){
            if(leftmax < rightmax){
                l++;
                leftmax = max(leftmax, height[l]);
                ans += leftmax - height[l];
            }else{
                r--;
                rightmax = max(rightmax, height[r]);
                ans += rightmax-height[r];
            }
        }
        return ans;
    }
};