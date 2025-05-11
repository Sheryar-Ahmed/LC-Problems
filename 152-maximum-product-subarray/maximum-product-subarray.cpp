class Solution {
public:
int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int curMax = nums[0], curMin = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) swap(curMax, curMin);   // flip on negative

        curMax = max(nums[i], curMax * nums[i]);
        curMin = min(nums[i], curMin * nums[i]);

        res = max(res, curMax);
    }
    return res;
}

};