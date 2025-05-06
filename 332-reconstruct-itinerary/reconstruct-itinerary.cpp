class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);  // maintain lexical order using min-heap
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(), res.end()); // because we build path in reverse
        return res;
    }

private:
    void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& res) {
        auto& pq = adj[src];
        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next, adj, res);
        }
        res.push_back(src); // add to path after all edges are used (post-order)
    }
};
