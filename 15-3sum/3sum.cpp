class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // fix 1 and find the two with two pinter technique
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else if (nums[left] + nums[right] + nums[i] == 0) {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    // also check the next is a duplicate or not both in left
                    // and right and skip
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};