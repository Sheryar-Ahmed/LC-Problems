class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            while (i > 0 && i < n && nums[i] == nums[i - 1])
                i++; // skip duplicates
            int L = i + 1;
            int R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    while(L < R && nums[L] == nums[L+1]) L++; 
                    while(L < R && nums[R] == nums[R-1]) R--; 
                    L++;
                    R--;
                } else if (sum < 0) {
                    L++;
                } else {
                    R--;
                }
            }
        }
        return ans;
    }
};