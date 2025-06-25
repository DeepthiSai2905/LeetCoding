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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq; // min heap
        ListNode* result=new ListNode(-1);
        ListNode* curr=result;
        for(ListNode* head: lists){
            if(head) pq.push(head);
        }
        while(!pq.empty()){
            ListNode* mini=pq.top();
            cout<<"mini "<<mini->val<<endl;
            pq.pop();
            curr->next=mini;
            if(mini->next){
                pq.push(mini->next);
            }
            curr=curr->next;
        }
        return result->next;

    }
};