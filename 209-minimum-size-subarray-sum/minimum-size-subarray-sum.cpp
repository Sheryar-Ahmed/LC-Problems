class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, currSum = 0;
        int minLen = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            currSum += nums[r];

            // shrink the window while sum is sufficient
            while (currSum >= target) {
                minLen = min(minLen, r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
