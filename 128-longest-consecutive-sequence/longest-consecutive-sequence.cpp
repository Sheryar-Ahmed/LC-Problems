class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {                // iterate over the set (not nums)
            if (!s.count(num - 1)) {       // only start from the beginning of a run
                int curr = num;
                int length = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
