class Solution {
public:
    bool canJump(vector<int>& nums) {
        // the main intuition is if my current index is greater than my farthest index i can reach we are stuck buddy
        int farthest = 0;
        for(int i=0; i < nums.size(); i++){
            if(i > farthest) return false;
            farthest = max(farthest, i+nums[i]);
        }
        return true;
    }
};