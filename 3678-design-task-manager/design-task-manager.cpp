using pii = pair<int, int>;

class TaskManager {
    multiset<array<int, 3>> S;
    map<int, pii> mp2;

public:
    TaskManager(vector<vector<int>> &tasks) {
        for (auto &it: tasks) {
            int x = it[0], y = it[1], z = it[2];
            mp2[y] = {x, z};
            S.insert({z, y, x});
        }
    }

    void add(int x, int y, int z) {
        mp2[y] = {x, z};
        S.insert({z, y, x});
    }

    void edit(int y, int nz) {
        auto [x, z] = mp2[y];
        mp2[y] = {x, nz};
        S.extract({z, y, x});
        S.insert({nz, y, x});
    }

    void rmv(int y) {
        auto [x, z] = mp2[y];
        mp2.erase(y);
        S.extract({z, y, x});
    }

    int execTop() {
        if (S.empty()) return -1;
        auto [z, y, x] = *S.rbegin();
        rmv(y);
        return x;
    }
};
