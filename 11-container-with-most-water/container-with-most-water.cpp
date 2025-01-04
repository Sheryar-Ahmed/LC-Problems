class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxAr = 0;
        while(i < j){
            //calculate which height is smaller
            int h = min(height[i], height[j]);
            int width = j-i;
            int area = h*width;
            maxAr = max(maxAr, area);
            // question when to move left and right pointer. move left if its shorter than right because ultimately the shorter height will give us more results rather than taller.
            if(height[i] < height[j]){
                i++;
            }else {
                j--;
            }
        }
        return maxAr;
    }
};