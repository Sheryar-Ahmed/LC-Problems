class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int L = 0;
        int maxIndex = 0;

        // Find initial max index
        for (int i = 0; i < k; i++) {
            if (nums[i] >= nums[maxIndex]) {
                maxIndex = i;
            }
        }
        ans.push_back(nums[maxIndex]);

        for (int R = k; R < nums.size(); R++) {
            L++; // move window

            // Check if maxIndex is out of window
            if (maxIndex < L) {
                // Recompute max in window
                maxIndex = L;
                for (int i = L; i <= R; i++) {
                    if (nums[i] >= nums[maxIndex]) {
                        maxIndex = i;
                    }
                }
            } else if (nums[R] >= nums[maxIndex]) {
                // New max enters window
                maxIndex = R;
            }

            ans.push_back(nums[maxIndex]);
        }

        return ans;
    }
};
