class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals by start
        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b){
            return a[0] < b[0]; // ascending order by start
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i < intervals.size(); i++){
            int s = intervals[i][0]; // 8, 1
            int e = intervals[i][1]; // 10, 6
            if(s <= ans.back()[1] && e > ans.back()[1]){
                ans.back()[1] = e;
            }else if(s > ans.back()[1] && e > ans.back()[1]){
                ans.push_back({s, e});
            }
        }
        return ans;
    }
};