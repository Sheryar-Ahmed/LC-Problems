class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lim = n/3;
        unordered_map<int, int> fq;
        // count the frequences 
        for(int &x: nums){
            fq[x]++;
        }
        vector<int> ans;
        for(auto m: fq){
            if(m.second > lim){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};