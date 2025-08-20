class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId;   // email -> index
        unordered_map<string, string> emailToName; // email -> name
        int id = 0;

        // Step 1: Assign each email an id
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                string email = acc[i];
                if (!emailToId.count(email)) {
                    emailToId[email] = id++;
                    emailToName[email] = name;
                }
            }
        }

        parent.resize(id);
        iota(parent.begin(), parent.end(), 0); // initialize DSU parent

        // Step 2: Union emails in the same account
        for (auto& acc : accounts) {
            int firstId = emailToId[acc[1]];
            for (int i = 2; i < acc.size(); i++) {
                unite(firstId, emailToId[acc[i]]);
            }
        }

        // Step 3: Group emails by their root parent
        unordered_map<int, vector<string>> groups;
        for (auto& [email, idx] : emailToId) {
            int root = find(idx);
            groups[root].push_back(email);
        }

        // Step 4: Build result
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(emailToName[emails[0]]); // name
            merged.insert(merged.end(), emails.begin(), emails.end());
            result.push_back(merged);
        }

        return result;
    }
};
