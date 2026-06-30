class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode *slow=head,*fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *prev=NULL,*curr=slow->next;
        slow->next=NULL;

        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        ListNode *first=head,*second=prev;

        while(second){
            ListNode *t1=first->next;
            ListNode *t2=second->next;

            first->next=second;
            second->next=t1;

            first=t1;
            second=t2;
        }
    }
};