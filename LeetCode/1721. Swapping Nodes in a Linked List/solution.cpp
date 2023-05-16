/*

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstN = head;
        while(k != 1){
            firstN = firstN->next;
            k--; 
        }
        ListNode* front = firstN;
        ListNode* slow = head;

        while(front->next != NULL){
            slow = slow->next;
            front = front->next;
        }

        int temp = firstN->val;
        firstN->val = slow->val;
        slow->val = temp;

        return head;
    }
};
