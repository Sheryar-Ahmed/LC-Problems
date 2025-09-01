class Solution {
public:
enum State { GOOD, BAD, UNKNOWN };

bool canJumpFrom(int pos, vector<int>& nums, vector<State>& memo) {
    if (memo[pos] != UNKNOWN) return memo[pos] == GOOD;

    int furthest = min((int)nums.size() - 1, pos + nums[pos]);
    for (int next = pos + 1; next <= furthest; next++) {
        if (canJumpFrom(next, nums, memo)) {
            memo[pos] = GOOD;
            return true;
        }
    }
    memo[pos] = BAD;
    return false;
}

bool canJump(vector<int>& nums) {
    vector<State> memo(nums.size(), UNKNOWN);
    memo[nums.size() - 1] = GOOD;
    return canJumpFrom(0, nums, memo);
}
};