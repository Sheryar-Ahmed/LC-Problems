class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int target = 0;
        for (int i = 0; i < nums.size() - 2;
             i++) { // fix one and find two elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip duplicates.
            int L = i + 1;
            int R = nums.size() - 1;
            while (L < R) {
                int sum = nums[L] + nums[R] + nums[i];
                if (sum == target) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    // after pushing check for next elments are duplicates skip
                    // untill
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R] == nums[R - 1]) R--;
                    L++;
                    R--;
                } else if (sum < target) {
                    L++;
                } else {
                    R--;
                };
            }
        }
        return ans;
    }
};