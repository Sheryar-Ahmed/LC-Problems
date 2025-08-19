class Solution {
private:
bool dfs(int node, unordered_map<int, vector<int>> &adj, int n, vector<int>& state){
    state[node] = 1; // set to visiting
    for(auto nei: adj[node]){
        if(state[nei] == 1) return false; // two can't be in process which means there is a cycle
        if(state[nei] == 0) {
            if(!dfs(nei, adj, n, state)){
                return false;
            }
        }        
    }
    state[node] = 2;
    return true;
}
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]); // b --> a
        }
        vector<int> state(numCourses, 0); // 0 univisted, 1 visiting,2 visited;
        for(int i=0; i < numCourses; i++){
            if(state[i] == 0){
                if(!dfs(i, adj, numCourses, state)){
                    return false;
                }
            }
        }
        return true;
    }
};