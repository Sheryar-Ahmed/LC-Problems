class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j < nums.size(); j++){
            if(nums[j] != nums[i]){ // found unique element
                nums[++i] = nums[j]; // lets replace it
            }
        }
        return i+1;
    }
};