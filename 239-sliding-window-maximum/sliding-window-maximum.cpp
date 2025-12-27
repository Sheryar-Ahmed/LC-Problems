class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int maxVal = INT_MIN;
        int maxIdx = -1;

        for (int i = 0; i < nums.size(); i++) {

            // Case 1: previous max went out of window
            if (maxIdx < i - k + 1) {
                maxVal = nums[i];
                maxIdx = i;

                // recompute max in current window
                for (int j = i - 1; j >= i - k + 1; j--) {
                    if (nums[j] > maxVal) {
                        maxVal = nums[j];
                        maxIdx = j;
                    }
                }
            }
            // Case 2: previous max still valid
            else {
                if (nums[i] >= maxVal) {
                    maxVal = nums[i];
                    maxIdx = i;
                }
            }

            if (i >= k - 1) {
                ans.push_back(maxVal);
            }
        }

        return ans;
    }
};
