class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // Correct dummy node initialization
        ListNode* current = dummy;        // Pointer to build the result list
        int carry = 0;

        while (l1 || l2 || carry) {       // Continue until both lists and carry are exhausted
            int sum = carry;              // Start with carry
            if (l1) {
                sum += l1->val;
                l1 = l1->next;            // Move to the next node in l1
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;            // Move to the next node in l2
            }
            carry = sum / 10;             // Calculate carry for the next iteration
            current->next = new ListNode(sum % 10); // Create a new node with the digit
            current = current->next;     // Move the pointer forward
        }

        return dummy->next;              // Return the result list, skipping dummy node
    }
};
