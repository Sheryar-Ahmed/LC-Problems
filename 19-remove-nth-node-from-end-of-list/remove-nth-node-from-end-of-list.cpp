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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // intuitn is to intially make the gap between the left and right pointer and move them so when the right pointer reaches end our left pointer will be at the node that's needs to be removed, inorder to be at the prev node we will do create a dummy node and makes its next to the head and initalize our left to that dummy so will be at the prev node
        ListNode dummy(0);
        dummy.next = head;
        ListNode* left = &dummy;
        ListNode* right = head;
        while(n--) {
            right = right->next;
        }
        // now just need to shift both left and right
        while(right) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy.next;
    }
};