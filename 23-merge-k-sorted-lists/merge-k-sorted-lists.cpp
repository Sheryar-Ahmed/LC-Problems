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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if( n== 0){
            return NULL;
        }
        while(n > 1){
            for(int i=0;i< n/2;i++){
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
        n = (n+1)/2;
        }
        return lists.front();
    }
private:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* temp_node = new ListNode(0);
    ListNode* curr_node = temp_node;

    while(list1 != NULL && list2 != NULL){
        if(list1->val <= list2->val){
            curr_node->next = list1;
            list1 = list1->next;
        }
        else{
            curr_node->next = list2;
            list2 = list2->next;
        }

        curr_node = curr_node->next;
    }
    if(list1 != NULL){
        curr_node->next = list1;
    }
    if(list2 != NULL){
        curr_node->next = list2;
    }

    return temp_node->next;
}

};