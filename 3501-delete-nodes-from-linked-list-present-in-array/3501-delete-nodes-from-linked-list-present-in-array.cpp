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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==NULL) return head;
        unordered_set<int>uniq(nums.begin(),nums.end());
        while(head && uniq.find(head->val)!=uniq.end()){
            head=head->next;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            if(uniq.find(temp->val)!=uniq.end()){ // found
                    prev->next=temp->next;
            }
            else prev=temp; // not found
            temp=temp->next;
        }
        return head;

    }
};