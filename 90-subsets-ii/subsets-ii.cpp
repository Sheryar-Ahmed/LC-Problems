class Solution {
private:
vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        backtrack(nums, path, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<int>& path, int start){
        ans.push_back(path);
        for(int i=start; i < nums.size(); i++){
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]); // choose
            backtrack(nums, path, i+1); // explore
            path.pop_back();
        }
    }
};