class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;

        while (L <= R) {
            int mid = L + (R - L) / 2;

            // Check if the middle element is the target
            if (nums[mid] == target) {
                return mid;
            }

            // Determine if the left half is sorted
            if (nums[L] <= nums[mid]) {
                // Check if the target lies within the sorted left half
                if (nums[L] <= target && target < nums[mid]) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if the target lies within the sorted right half
                if (nums[mid] < target && target <= nums[R]) {
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};
