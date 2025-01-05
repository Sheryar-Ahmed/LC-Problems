class TaskManager {
public:
    // multiset to set the priority, it automatically sorts.
    multiset<array<int, 3>> S;
    map<int, pair<int, int>> m;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks) {
            int x = it[0], y = it[1], z = it[2];
            m[y] = {x, z};
            S.insert({z, y, x});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        m[taskId] = {userId, priority};
        S.insert({priority, taskId, userId});        
    }
    
    void edit(int taskId, int newPriority) {
        auto [x, z] = m[taskId];
        m[taskId] = {x, newPriority};
        S.extract({z, taskId, x});
        S.insert({newPriority, taskId, x});
    }
    
    void rmv(int taskId) {
        auto [x, z] = m[taskId];
        m.erase(taskId);
        S.extract({z, taskId, x});
    }
    
    int execTop() {
        if(S.empty()) return -1;
        auto [z, y, x] = *S.rbegin(); // the iterator need to dereference, and also rebegin gives top
        rmv(y);
        return x;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */