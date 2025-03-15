class Solution {
public:
    bool check(vector<int>& nums, int mid, int k) {
        int count = 0;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] <= mid) {
                count++;
                i += 2; // Move two steps forward to ensure non-adjacency
            } else {
                i++; // Skip this element
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(nums, mid, k)) {
                result = mid;
                right = mid - 1; // Search for a smaller valid mid
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
