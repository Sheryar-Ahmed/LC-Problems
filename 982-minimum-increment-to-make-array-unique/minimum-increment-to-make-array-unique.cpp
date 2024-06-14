class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minInc = 0;
        for(int i=1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                nums[i] = nums[i]+1;
                minInc += 1;
            }else if(nums[i] < nums[i-1]){ //if it is small than the prev element
                minInc += (nums[i-1]-nums[i])+1;
                nums[i] = nums[i]+((nums[i-1]-nums[i])+1);
            }else{
                continue;
            }
        }

        return minInc;
    }
};