class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // stack to store indices
        int trapped = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {
            // While the current height is greater than the top of stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if (st.empty()) break; // No left boundary

                int left = st.top(); // Left boundary
                int width = i - left - 1;
                int minHeight = min(height[left], height[i]) - height[bottom];
                trapped += width * minHeight;
            }
            st.push(i); // always push current index
        }

        return trapped;
    }
};
