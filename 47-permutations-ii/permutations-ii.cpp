class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, path, used); // nums, currenpath, used
        return ans;
    }
    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used ){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i=0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if(used[i]) continue; // skip
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, path, used); // same element
            path.pop_back();
            used[i] = false;
        }
    }
};