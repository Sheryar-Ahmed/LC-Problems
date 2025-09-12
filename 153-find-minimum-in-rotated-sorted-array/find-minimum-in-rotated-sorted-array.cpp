class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // min must be in right half
                left = mid + 1;
            } else {
                // min is in left half including mid
                right = mid;
            }
        }

        return nums[left]; // or nums[right]
    }
};
