class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort them
        sort(intervals.begin(), intervals.end(), [](const auto &a,const auto &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // its a overlap
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};