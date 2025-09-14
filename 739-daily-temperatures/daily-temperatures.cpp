class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // for each day find the next greater hoter day.
        stack<int> stack;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0;i < n; i++){
            while(!stack.empty() && temperatures[i] > temperatures[stack.top()]){
                int idx = stack.top();
                stack.pop();
                ans[idx] = i-idx;
            }
            stack.push(i);
        }
        return ans;
    }
};