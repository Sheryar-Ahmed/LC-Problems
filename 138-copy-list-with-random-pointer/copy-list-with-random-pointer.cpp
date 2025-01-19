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
        unordered_map<Node*, Node*> oldToCopy;
        Node* curr = head;
        while(curr){
            oldToCopy[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node* copy = oldToCopy[curr];
            copy->next=oldToCopy[curr->next];
            copy->random=oldToCopy[curr->random];
            curr = curr->next;
        }
        return oldToCopy[head];
    }
};