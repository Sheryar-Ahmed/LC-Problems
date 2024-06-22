class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int ans = 0;
        int prefix = 0; // This will help in counting valid subarrays
        
        while (j < nums.size()) {
            if (nums[j] % 2 != 0) {
                count++;
                prefix = 0; // Reset the prefix count when a new odd number is encountered
            }
            
            while (count == k) {
                prefix++; // Count the number of valid subarrays ending at `j`
                if (nums[i] % 2 != 0) {
                    count--;
                }
                i++;
            }
            
            ans += prefix; // Add the number of valid subarrays to the answer
            j++;
        }
        
        return ans;
    }
};
