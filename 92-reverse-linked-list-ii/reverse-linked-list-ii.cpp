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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        // reach node at position left before left;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // reversing the sublist
        ListNode* current = prev->next;
        ListNode* leftPointer = prev; // leftpointer is before the current 
        for (int i = 0; i < right - left+1; ++i) {
            ListNode* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        
        // updating pointers
        leftPointer->next->next = current;
        leftPointer->next = prev;
        
        return dummy.next;
    }
};