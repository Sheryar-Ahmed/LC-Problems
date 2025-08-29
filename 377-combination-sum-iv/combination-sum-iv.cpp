class Solution {
private:
    unordered_map<int, int> memo;

public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        memo[0] = 1;
        return dfs(nums, target);
    }

    int dfs(vector<int>& nums, int total) {
        if (memo.count(total)) {
            return memo[total];
        }

        int res = 0;
        for (int num : nums) {
            if (total < num) {
                break;
            }
            res += dfs(nums, total - num);
        }
        memo[total] = res;
        return res;
    }
};