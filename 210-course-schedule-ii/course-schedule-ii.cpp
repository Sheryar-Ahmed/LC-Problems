class Solution {
public:
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int n, vector<int> &indegree){
        vector<int> ans;
        queue<int> q;
        int count = 0;
        // pushing all those have zero degree
        for(int i=0; i < n; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
                q.push(i); 
                count++;
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    ans.push_back(v);
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == n){
            return ans;
        }else{
            return {};
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // kahn's algo
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return topologicalSort(adj, numCourses, indegree);
    }
};