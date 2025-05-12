class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // you're stuck
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
