class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) { //left not found which means start of seq
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) { // num+length because number is same
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};