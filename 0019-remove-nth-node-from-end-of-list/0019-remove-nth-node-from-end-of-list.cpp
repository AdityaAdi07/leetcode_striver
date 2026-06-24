class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0; i < n; i++)
            fast = fast->next;

        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;

        slow->next = del->next;

        delete del;

        return dummy->next;
    }
};