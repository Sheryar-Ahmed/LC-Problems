class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto &x: nums){
            freq[x]++;
            if(freq[x] > n / 2) return x;
        }
        // for(auto &it: freq){
        //     if(it.second > n / 2) return it.first;
        // }
        return -1;
    }
};