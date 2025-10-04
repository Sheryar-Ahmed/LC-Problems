class Solution {
public:
    bool dfs(int node, vector<int>&state, vector<vector<int>>& adj){
        if(state[node] == 1){ // check if already processing then we got a cycle 
            return false;
        }
        if(state[node] == 2){ // check if its processed
            return true;
        }
        state[node] = 1; // put into visitng 
        for(auto &nei: adj[node]){
           if(!dfs(nei, state, adj)){
                return false;
            }
        }
        state[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adj list
        vector<vector<int>> adj(numCourses);
        for(auto vec: prerequisites){
            int a = vec[0]; int b = vec[1];
            adj[b].push_back(a);
        }
        vector<int> state(numCourses, 0); // 0 univisted, 1 visiting, 2 is visited;
        for(int i=0; i <numCourses; i++){
            if(state[i] == 0){
                if(!dfs(i, state, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};