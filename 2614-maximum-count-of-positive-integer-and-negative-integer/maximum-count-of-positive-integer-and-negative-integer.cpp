class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the first positive number index >=1
        int posIndex = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        
        // Find the index >=0, then subtract one to get the last negative index
        int negIndex = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        int posCount = n - posIndex;
        int negCount = negIndex;
        
        return max(posCount, negCount);
    }
};
