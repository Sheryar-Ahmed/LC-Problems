class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]]; // why now just fast because if i do both has initial 0 will be equal
        }while(slow != fast);
        // found intersection
        int slow2 = 0;
        while(slow2 != slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};