class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // skip duplicates for j

                int L = j + 1;
                int R = n - 1;

                while (L < R) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[L] + nums[R];  // to avoid overflow

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L + 1]) L++;
                        while (L < R && nums[R] == nums[R - 1]) R--;
                        L++;
                        R--;
                    } else if (sum < target) {
                        L++;
                    } else {
                        R--;
                    }
                }
            }
        }
        return ans;
    }
};
