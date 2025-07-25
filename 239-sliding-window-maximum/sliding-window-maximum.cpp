class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // will store **indices** of useful elements
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices out of the current window from the front
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements smaller than the current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Window of size k is formed, record the max
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
