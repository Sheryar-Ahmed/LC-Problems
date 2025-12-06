/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*  curr = head;
        // ensure k nodes exists before reverse
        for(int i=0; i < k; i++){
            if(!curr) return head;
            curr = curr->next;
        }
        // reverse k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head; 
        for(int i=0; i < k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev; // this will hold the group;
    }
};