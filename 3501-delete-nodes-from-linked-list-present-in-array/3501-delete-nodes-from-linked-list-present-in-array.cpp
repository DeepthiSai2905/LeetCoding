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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp=head;
        ListNode* prev=dummy;
        while(temp){
            if (uniq.count(temp->val)) {
               prev->next = temp->next;
               //delete(temp); // Optional if memory management is required
            } else {
                prev = temp;
            }
            temp=temp->next;
        }
        return dummy->next;

    }
};