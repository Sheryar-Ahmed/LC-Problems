class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: sort by start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        // Step 2: start with the first interval
        ans.push_back(intervals[0]);

        // Step 3: iterate through all intervals
        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = ans.back()[1];   // end of the last interval in ans
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (lastEnd >= currStart) {
                // merge by updating the end of the last interval
                ans.back()[1] = max(lastEnd, currEnd);
            } else {
                // no overlap, just add this interval
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
