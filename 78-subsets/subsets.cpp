class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& path, int start) {
        result.push_back(path); // record current subset

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);              // choose
            backtrack(nums, path, i + 1);         // explore
            path.pop_back();                      // un-choose
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return result;
    }
};
