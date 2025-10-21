class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        // we can count the frequent elements and send them back
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto& x : nums) {
            mp[x]++;
        }
        vector<pair<int, int>> con(mp.begin(), mp.end());
        // sort mp by their frequency and then return top k elements.
        sort(con.begin(), con.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; }); // descending comparator, we cannot sort 

        for (auto& v : con) {
            if (k > 0) {
                ans.push_back(v.first);
                k--;
            } else {
                break;
            }
        }
        return ans;
    }
};