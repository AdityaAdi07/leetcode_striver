class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;

        // Move to left position
        for(int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* connection = prev;
        ListNode* tail = curr;

        // Reverse
        for(int i = 0; i < right-left+1; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Connect first part
        if(connection != NULL)
            connection->next = prev;
        else
            head = prev;

        // Connect last part
        tail->next = curr;

        return head;
    }
};