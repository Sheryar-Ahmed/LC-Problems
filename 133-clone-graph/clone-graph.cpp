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
private:
unordered_map<Node*, Node*> old_to_clone;
void dfs(Node* node){
    for(auto &n: node->neighbors){
        if(old_to_clone.find(n) == old_to_clone.end()){
            Node* clone = new Node(n->val);
            old_to_clone[n] = clone;
            old_to_clone[node]->neighbors.push_back(clone);
            dfs(n);
        }else{
            old_to_clone[node]->neighbors.push_back(old_to_clone[n]);
        }
    }
}
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* clone = new Node(node->val);
        old_to_clone.clear();
        old_to_clone[node] = clone;
        dfs(node);
        return clone;
    }
};