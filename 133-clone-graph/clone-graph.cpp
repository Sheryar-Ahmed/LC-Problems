class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;

        // clone starting node
        visited[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for(Node* neigh : curr->neighbors) {
                // if neighbor not cloned yet
                if(visited.find(neigh) == visited.end()) {
                    visited[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                // connect clone
                visited[curr]->neighbors.push_back(visited[neigh]);
            }
        }

        return visited[node];
    }
};
