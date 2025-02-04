class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap with custom comparator (stores {distance, x, y})
        priority_queue<vector<int>> maxHeap;
        
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x * x + y * y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();  // Remove farthest point
            }
        }
        
        vector<vector<int>> result;
        result.reserve(k);  // Reserve space for optimization

        while (!maxHeap.empty()) {
            const auto& top = maxHeap.top();  // Avoid unnecessary copying
            result.push_back({top[1], top[2]});
            maxHeap.pop();
        }
        
        return result;
    }
};
