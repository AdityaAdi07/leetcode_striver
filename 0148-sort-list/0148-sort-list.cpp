class Solution {
public:
    ListNode* mid(ListNode* head){
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* a,ListNode* b){
        ListNode dummy;
        ListNode* curr=&dummy;

        while(a && b){
            if(a->val < b->val){
                curr->next=a;
                a=a->next;
            }else{
                curr->next=b;
                b=b->next;
            }
            curr=curr->next;
        }

        curr->next = a ? a : b;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* m = mid(head);
        ListNode* right = m->next;
        m->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left,right);
    }
};