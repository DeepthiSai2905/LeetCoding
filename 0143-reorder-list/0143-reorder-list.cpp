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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; 
        ListNode* rev = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        ListNode* middle = slow;
        ListNode* rev=reverseList(middle->next);
        slow->next=NULL;
        ListNode* curr=head;
        ListNode* nxt;
        while(rev){ // 2nd half rev <= 1st half curr
            nxt = curr->next;
            curr->next=rev;
            rev=rev->next;
            curr->next->next=nxt;
            curr=nxt;
        }
    }
};