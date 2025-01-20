class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        // find the first intersection
        while(true){
            slow = nums[slow]; //  move slowly
            fast = nums[nums[fast]]; // move fastly
            if(slow == fast){ // found that index they intersected
                break;
            }
        }
        // find the second interaction by slow 2 pointer
        int slow2 = 0; // starting from the first index
        while(true){
            slow = nums[slow]; //
            slow2 = nums[slow2]; // the distance between them is gonna always be 1
            if(slow == slow2){
                return slow;
            }
        }
    }
};