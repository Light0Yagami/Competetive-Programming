/*Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

*/
class Solution {
public:
/*              REVURSIVE 
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head->next;

        head->next = swapPairs(head->next->next);
        temp->next = head;


        return temp;
    }

*/

    ListNode* swapPairs(ListNode* head) {
        ListNode* dnode = new ListNode(-1);
        ListNode* prev = dnode;
        ListNode* curr = head;
        dnode->next = head;

        while(curr != NULL && curr->next != NULL){
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            curr = curr->next;
            prev = prev->next->next;
        }

        return dnode->next;
    }
};
