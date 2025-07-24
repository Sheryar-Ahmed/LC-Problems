class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;  // normalize k

        // Step 1: reverse the entire array
        reverse(nums, 0, n - 1);

        // Step 2: reverse the first k elements
        reverse(nums, 0, k - 1);

        // Step 3: reverse the remaining elements
        reverse(nums, k, n - 1);
    }
};
