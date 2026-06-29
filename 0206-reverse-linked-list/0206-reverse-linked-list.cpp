class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {

            ListNode* nxt = curr->next;   

            curr->next = prev;        

            prev = curr;   

            curr = nxt;                  
        }

        return prev;
    }
};