class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0]; // 2
        int fast = nums[0]; // 2
        do {
            slow = nums[slow];       // 9
            fast = nums[nums[fast]]; // 1
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};