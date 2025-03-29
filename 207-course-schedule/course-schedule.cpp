class Solution {
public:
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true; // remember example of 1--->2<---3 current recursion stack thing
        for(auto v: adj[u]){
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)){
                return true; // cycle found
            }else if(inRecursion[v]){
                return true; // if its not visited but we reached the current recursion again which means we are in cycle
            }
        }
        inRecursion[u] = false; // we cannot call dfs further so we return our stack.
        return false; // no cycle found
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // with dfs
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
        }

        for(int i=0; i < numCourses; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)){
                return false;
            }
        }
        return true;
    }
};