class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prefix = 1;
        for(int i=0; i < n; i++){
            res[i] = prefix;
            //compute prefix(product of elements before it) for next
            prefix *= nums[i];
        }
        int suffix = 1;
        // now we will calculate suffix(product of elements after it) which is 
        for(int i=n-1; i >= 0; --i){
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};