class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (int val : arr) {
            pq.push({abs(val - x), val});
        }

        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end()); // Return sorted order
        return ans;
    }
};
