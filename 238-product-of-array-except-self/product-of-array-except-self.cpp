class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n < 2 ) return nums;
        vector<int> prefixProd(n, 1);
        vector<int> suffixProd(n, 1);
        
        prefixProd[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
        }
        suffixProd[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixProd[i] = suffixProd[i + 1] * nums[i];
        }
        vector<int> ans;
        // now i have both suffix and prefix products
        for (int i = 0; i < n; i++) {
            int calc = (i - 1 >= 0 ? prefixProd[i - 1] : 1) *
                       (i + 1 < n ? suffixProd[i + 1] : 1);
            ans.push_back(calc);
        }
        return ans;
    }
};