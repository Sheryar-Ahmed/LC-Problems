class Solution {
public:
    int total = 0;

    void backtrack(vector<int>& nums, vector<int>& path, int start) {
        // Calculate XOR for current path (subset)
        int xorVal = 0;
        for (int num : path) {
            xorVal ^= num;
        }
        total += xorVal;

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);             // choose
            backtrack(nums, path, i + 1);         // explore
            path.pop_back();                      // un-choose (backtrack)
        }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return total;
    }
};
