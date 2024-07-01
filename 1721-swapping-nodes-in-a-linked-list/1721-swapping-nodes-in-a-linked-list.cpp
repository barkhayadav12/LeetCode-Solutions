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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*temp=head;
        int cnt=0;
        int val1=0;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==k)
            {
                val1=temp->val;
                break;
            }
            temp=temp->next;
        }
        int tot_cnt=0;
        temp=head;
        while(temp!=NULL)
        {
            tot_cnt++;
            temp=temp->next;
        }
        int lastInd=tot_cnt-k+1;
        int cnt_two=0;
        temp=head;
        int val2=0;
        while(temp!=NULL)
        {
            cnt_two++;
            if(cnt_two==lastInd)
            {
                val2=temp->val;
                break;
            }
            temp=temp->next;
        }
        temp=head;
        cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==k)
            {
                temp->val=val2;
            }
            if(cnt==lastInd)
            {
                temp->val=val1;
            }
            temp=temp->next;
        }
        return head;
    }
};