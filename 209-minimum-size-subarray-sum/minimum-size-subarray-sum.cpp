class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int currentWindowSum = 0;
        int res = INT_MAX;
        for(int R=0; R < nums.size(); R++){
            currentWindowSum+= nums[R];
            while(currentWindowSum >= target){
                res = min(R-L+1, res);
                currentWindowSum-=nums[L];
                L++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};