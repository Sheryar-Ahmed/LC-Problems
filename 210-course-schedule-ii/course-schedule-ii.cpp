class Solution {
private:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        vector<int> ans;
        queue<int> q;
        int count = 0;

        // Step 1: start with nodes having indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
                q.push(i);
                count++;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                indegree[v]--;          // one prereq is done
                if (indegree[v] == 0) { // now course is free to take
                    ans.push_back(v);
                    q.push(v);
                    count++;
                }
            }
        }
        if (count == n) {
            return ans;
        } else {
            return {};
        }
    };

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a); // b -> a (b must be done before a)
            indegree[a]++;       // a has one more prerequisite
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};