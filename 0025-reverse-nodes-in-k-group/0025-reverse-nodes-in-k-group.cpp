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
    ListNode* rev(ListNode* head, ListNode* tail){
        //  cout<<"->"<<head->val<<"-"<<tail->val<<"\n";
        if(head==tail) return head;
        ListNode* head2 = rev(head->next, tail);
        head->next->next = head;
        head->next=NULL;
        return head2;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int x=0;
        ListNode* temp=head;
        while(x<k-1 && temp){
            x++;
            temp=temp->next;
        }
        if(x!=k-1 || !temp) return head;
        // cout<<"->"<<temp->val<<"temp-"<<"\n";
        ListNode* nextGroup = temp->next; 
        ListNode* newHead = rev(head, temp);
        head->next=reverseKGroup(nextGroup,k);
        return newHead;
    }
};