/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*>& oldToClone) {
        if(!node) return;
        for (auto nei : node->neighbors) {
            if (oldToClone[nei]) {
                oldToClone[node]->neighbors.push_back(oldToClone[nei]);
            } else {
                oldToClone[nei] = new Node(nei->val);
                oldToClone[node]->neighbors.push_back(oldToClone[nei]);
                dfs(nei, oldToClone);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToClone;
        if(!node) return nullptr;
        oldToClone[node] = new Node(node->val);

        dfs(node, oldToClone);
        return oldToClone[node];
    }
};