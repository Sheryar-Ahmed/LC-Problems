class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue; // skip duplicates.
            if (nums[i] == nums[i - 1] + 1) {
                // it means its the next element
                curr++;
            } else {
                longest = max(longest, curr);
                // otherwise new started.
                curr = 1;
            }
        }
        longest = max(longest, curr);
        return longest;
    }
};