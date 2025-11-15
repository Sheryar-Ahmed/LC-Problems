class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return min(nums[0], nums[1]);
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                right--;
            } else {
                left++;
            }
        }
        return nums[left];
    }
};