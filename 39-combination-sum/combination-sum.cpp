class Solution {
private:
    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates, int target, vector<int>& path, int start) {
        if (target == 0) {
            ans.push_back(path);  // found valid combination
            return;
        }

        if (target < 0) return; // invalid path (prune)

        for (int i = start; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);  // choose
            backtrack(candidates, target - candidates[i], path, i); // explore (i, not i+1) because we can reuse same element
            path.pop_back();  // un-choose
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(candidates, target, path, 0);
        return ans;
    }
};
