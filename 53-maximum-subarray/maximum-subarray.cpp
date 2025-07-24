class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = nums[0];
        int currSum = 0;
        for(auto &x: nums){
            if(currSum < 0){
                currSum = 0;
            }
            currSum+=x;
            largestSum = max(currSum, largestSum);
        }

        return largestSum;
    }
};