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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        ListNode* curr=head;
        int top=0,left=0,right=n-1,bot=m-1;
        int dir=0;
        while(curr){
            if(dir==0){
                for(int i=left;i<=right && curr;i++){
                    res[top][i]=curr->val;
                    curr=curr->next;
                }
                top++;
            }
            else if(dir==1){ // go down
                for(int i=top;i<=bot && curr;i++) {
                    res[i][right]=curr->val;
                    curr=curr->next;
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left && curr;i--){
                    res[bot][i]=curr->val;
                    curr=curr->next;
                }
                bot--;
            }
            else if(dir==3){
                for(int i=bot;i>=top && curr;i--){
                    res[i][left]=curr->val;
                    curr=curr->next;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};