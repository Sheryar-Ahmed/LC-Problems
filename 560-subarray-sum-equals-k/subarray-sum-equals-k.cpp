class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i < n; i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        unordered_map<int, int> m; // PrefixSum, freq;
        for(int j=0; j < n; j++){
            if(prefixSum[j] == k) count++; // case 1 direct equal
            int val = prefixSum[j]-k; // now this is the value
            if(m.find(val) != m.end()){ // case 2 if found
                count+=m[val];
            }
            m[prefixSum[j]]++;
        }
        return count;
    }
};