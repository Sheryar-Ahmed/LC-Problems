class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight; // ratio to parent

    string find(string x) {
        if (parent[x] != x) {
            string origParent = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origParent]; // update ratio to new parent
        }
        return parent[x];
    }

    void unite(string a, string b, double val) {
        if (!parent.count(a)) { parent[a] = a; weight[a] = 1.0; }
        if (!parent.count(b)) { parent[b] = b; weight[b] = 1.0; }

        string rootA = find(a);
        string rootB = find(b);

        if (rootA == rootB) return;

        // make rootA child of rootB
        parent[rootA] = rootB;
        // Adjust weight: a / b = val → weight[rootA] = (b / a)
        weight[rootA] = val * weight[b] / weight[a];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        // Step 1: Build DSU
        for (int i = 0; i < equations.size(); i++) {
            auto& eq = equations[i];
            unite(eq[0], eq[1], values[i]);
        }

        // Step 2: Answer queries
        vector<double> res;
        for (auto& q : queries) {
            string a = q[0], b = q[1];
            if (!parent.count(a) || !parent.count(b) || find(a) != find(b)) {
                res.push_back(-1.0);
            } else {
                res.push_back(weight[a] / weight[b]);
            }
        }
        return res;
    }
};
