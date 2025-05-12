class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // greedy approach here is whenever our sum hits negative reset it to 0
        int sum = 0;
        int MaxSum = nums[0];
        for(int i=0; i <= nums.size()-1; i++){
            if(sum < 0){
                sum = 0;
            }
            sum+=nums[i];
            MaxSum = max(MaxSum, sum);
        }
        return MaxSum;
    }
};