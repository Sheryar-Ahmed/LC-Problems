class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort it 
        sort(intervals.begin(), intervals.end(), [](const auto&a, const auto&b){
            return a[0] < b[0]; // ascending order
        });
        // initially we put the intervals index 0 to the answer and check the last element
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i < intervals.size(); i++){
            int last = ans.back()[1];
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(last >= a){
                // merge
                ans.back()[1] = max(last, b);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};