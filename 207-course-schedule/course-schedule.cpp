class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> adj, int n, vector<int> indegree) {
        queue<int> q;
        int count = 0; // kitne nodes mane viist krliey hai
        // those whose indgree is zero is pushed to the q
        for(int i=0 ;i < n; i++) {
            if(indegree[i]  == 0) {q.push(i); count++;};
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                    count++;
                }
            }
        }
        return count == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0); // kahn's algo

        for(auto &vec: prerequisites) {
            int a = vec[0];
            int b = vec[1];
            // b --> a
            adj[b].push_back(a);
            // count degree 'a' mei ja rha ha b say
            inDegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, inDegree);

    }
};