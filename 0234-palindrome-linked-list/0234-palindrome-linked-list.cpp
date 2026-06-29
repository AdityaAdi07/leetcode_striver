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
    bool isPalindrome(ListNode* head) {
        ListNode* mid=head;
        ListNode* fst=head;

        while(fst!=NULL && fst->next!=NULL){
            fst=fst->next->next;
            mid=mid->next;
        }
        ListNode* prev=NULL;
        while(mid!=NULL){
            ListNode* nxt= mid->next;
            mid->next=prev;
            prev=mid;
            mid=nxt;
        }
//prev contain reverese head
        while(prev!=NULL){
            if(head->val!=prev->val) return false;

            head=head->next;
            prev=prev->next;

        }
        return true;
        
    }
};