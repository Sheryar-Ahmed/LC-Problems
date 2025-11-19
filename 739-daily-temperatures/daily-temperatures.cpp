class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices, keeps a decreasing stack of temperatures

        for (int i = 0; i < n; i++) {
            // whenever current temperature is greater
            // it's the next greater temperature for the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx; // number of days to wait
            }
            st.push(i);
        }

        return ans;
    }
};
