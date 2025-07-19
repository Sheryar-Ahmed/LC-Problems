class Solution {
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // \U0001f448 important
        vector<int> path;
        backtrack(candidates, target, path, 0);
        return ans;
    }
    void backtrack(vector<int>& candidates, int target, vector<int>& path,
                   int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++) {
  // \U0001f512 Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            
            backtrack(candidates, target - candidates[i], path,
                      i + 1); // unique subsets
            path.pop_back();
        }
    }
};