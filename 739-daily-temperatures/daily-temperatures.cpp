class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mst;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            while (!mst.empty() && temperatures[i] > temperatures[mst.top()]) {
                int idx = mst.top();
                mst.pop();
                ans[idx] = i-idx;
            }
            mst.push(i);
        }
        return ans;
    }
};