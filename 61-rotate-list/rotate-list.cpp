class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // calculate length
        ListNode* craw = head;
        int size = 0;
        while (craw) {
            size++;
            craw = craw->next;
        }

        k = k % size;         // important fix
        int upto = size - k;  // correct rotation point

        if (upto == size) return head; // no rotation needed

        craw = head;

        // move upto-1 steps (so craw stops at new tail)
        for (int i = 1; i < upto; i++) {
            craw = craw->next;
        }

        // cut the list
        ListNode* rotated = craw->next;
        craw->next = nullptr;

        // go to the end of the rotated part
        ListNode* end = rotated;
        while (end->next) {
            end = end->next;
        }

        // attach old head at the end
        end->next = head;

        return rotated;
    }
};
