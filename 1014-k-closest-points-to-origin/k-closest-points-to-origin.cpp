class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap based on distance
        auto dist = [](vector<int>& p) {
            return p[0] * p[0] + p[1] * p[1]; // squared Euclidean distance
        };

        // pair: {distance, point}
        auto cmp = [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) {
            return a.first < b.first;  // max-heap (farthest on top)
        };

        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(cmp)> maxHeap(cmp);

        for (auto& point : points) {
            int d = dist(point);
            maxHeap.push({d, point});
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove the farthest
            }
        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
