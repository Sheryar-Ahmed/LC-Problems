/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // we can initally make the copy with just next and store the random in the hashmap and traverse hashamp and link our copy to the random node.
        unordered_map<Node*, Node*> oldToCopy; // original node, copy new node just with value
        Node* curr = head;
        while(curr) {
            oldToCopy[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr) {
            Node* copy = oldToCopy[curr];
            copy->next = oldToCopy[curr->next];
            copy->random = oldToCopy[curr->random];
            curr = curr->next;
        }
        return oldToCopy[head];
    }
};