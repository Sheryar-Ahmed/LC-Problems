class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;

        while (L < R) { // Use L < R to prevent unnecessary checks
            int mid = L + (R - L) / 2;

            // If mid is greater than R, the minimum is in the right half
            if (nums[mid] > nums[R]) {
                L = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (or mid itself)
            else {
                R = mid;
            }
        }

        // At the end, L == R, which is the index of the minimum element
        return nums[L];
    }
};
