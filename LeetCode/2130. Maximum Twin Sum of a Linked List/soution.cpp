/*
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/

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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
    
        int n = 1;

        while(temp->next != NULL){
            n++;
            temp = temp->next;
        }
        temp = head;
        stack<int> st;
        for(int i = 1; i <= n/2; i++){
            st.push(temp->val);
            temp = temp->next;
        }
        int ans = INT_MIN;
        while(!st.empty() && temp != NULL){
            int sum = st.top() + temp->val;
            temp = temp->next;
            st.pop();
            ans = max(ans,sum);
        }



        return ans;
    }
};




class Solution {
public:
int pairSum(ListNode* head) {
ListNode* slow = head;
ListNode* fast = head;
int maxVal = 0;
while(fast && fast -> next)
{
slow = slow -> next;
fast = fast -> next -> next;
}
ListNode *nextNode, *prev = NULL;
while (slow) {
nextNode = slow->next;
slow->next = prev;
prev = slow;
slow = nextNode;
}
while(prev)
{
maxVal = max(maxVal, head -> val + prev -> val);
prev = prev -> next;
head = head -> next;
}
return maxVal;
}
};
