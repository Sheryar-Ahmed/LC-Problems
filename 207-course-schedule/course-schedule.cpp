class Solution {
public:
    bool dfs(int node, vector<int>& state, vector<vector<int>>& adj) {
        // if the current node is already in state of visiting then cycle
        // detected and we cannot finish courses so return false
        if (state[node] == 1)
            return false;
        if (state[node] == 2)
            return true; // we need to skip this one.
        state[node] = 1;
        for (auto& nei : adj[node]) {
            if (!dfs(nei, state, adj))
                return false;
        }
        state[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // DAG, indegree+dfs(recursive stack);
        vector<vector<int>> adj(numCourses);
        for (auto& vec : prerequisites) {
            auto a = vec[0];
            auto b = vec[1];
            adj[b].push_back(a);
        }
        vector<int> state(
            numCourses); // 0 unvi, 1 mean visitiin, 2 done visited.
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (!dfs(i, state, adj))
                    return false; // cycle detected;
            }
        }
        return true;
    }
};