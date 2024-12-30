class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for(const auto &x: nums){
            freq[x]++; // count each number freq
        }
        // store each number with their freq in maxHeap 
        priority_queue<pair<int, int>> maxH;
        for(auto k: freq){
            maxH.push({k.second, k.first}); // now the most frequest element is at top 
        }
        // we need to pop those elements equal to K
        for (int i = 0; i < k; i++) {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;
    }
};