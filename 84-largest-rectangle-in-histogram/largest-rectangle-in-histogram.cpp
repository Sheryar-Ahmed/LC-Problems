class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack; // Pair: {index, height}
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int start = i; // Assume the current position as the starting index
            while (!stack.empty() && stack.top().second > heights[i]) {
                // Pop elements until we find a smaller height
                auto [index, height] = stack.top();
                stack.pop();
                maxArea = max(maxArea, height * (i - index)); // Calculate area
                start = index; // Update the start position
            }
            // Push the current height and its valid starting index
            stack.push({start, heights[i]});
        }

        // Process the remaining elements in the stack
        while (!stack.empty()) {
            auto [index, height] = stack.top();
            stack.pop();
            maxArea = max(maxArea, height * (n - index)); // Calculate area with width till the end
        }

        return maxArea;
    }
};
