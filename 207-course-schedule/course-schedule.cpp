class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &pre: prerequisites){
            auto a = pre[0];
            auto b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        int count = 0;
        for(int i=0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            auto u = q.front(); q.pop();
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }

        return numCourses == count;
    }
};