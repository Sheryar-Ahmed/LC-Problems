class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices of elements in decreasing order of value

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // If the window has reached size `k`, add the maximum to the result
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
