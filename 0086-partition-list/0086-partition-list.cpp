class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy, largeDummy;
        ListNode *small=&smallDummy, *large=&largeDummy;

        while(head){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }else{
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        large->next = NULL;
        small->next = largeDummy.next;

        return smallDummy.next;
    }
};