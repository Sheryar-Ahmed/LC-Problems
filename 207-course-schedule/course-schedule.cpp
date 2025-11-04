class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int front = q.front();
                q.pop();
                count++;
                for (auto& x : adj[front]) {
                    indegree[x]--;
                    if (indegree[x] == 0) {
                        q.push(x);
                    }
                }
            }
        }
        return count == numCourses;
    }
};