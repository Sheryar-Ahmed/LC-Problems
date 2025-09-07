class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        if (nums.size() == 1)
            return 1;
        // sort krlo
        // 1, 2, 3, 4, 100, 200
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {
            return a < b; // asc a > b // desc
        });
        // to get the start of the sequence if a subtract -1 from it, that must
        // not availble in the nums.
        unordered_set<int> look(nums.begin(), nums.end()); // fast lookups;
        int longest = 1;
        // for each element check if its has longest string
        int i = 0;
        // 0, 1, 1, 2
        while (i < nums.size()) {
            int currentLong = 1;
            // skip duplicates
            // while(i > 0 && i < nums.size() && nums[i] == nums[i-1]) continue;
            if (look.find(nums[i] - 1) == look.end()) {
                while (i < nums.size()-1 && nums[i] + 1 == nums[i + 1]) {
                    currentLong++;
                    i++;
                    while(i < nums.size()-1 && nums[i] == nums[i+1]) i++; // skip duplicates
                }
            }
            i++;
            longest = max(currentLong, longest);
        }

        return longest;
    }
};