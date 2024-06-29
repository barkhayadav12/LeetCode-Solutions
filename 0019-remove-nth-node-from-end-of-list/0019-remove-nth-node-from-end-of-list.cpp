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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if(cnt==n)
        {
            ListNode*newHead=head->next;
            return newHead;
        }
        ListNode*p=head;
        int res=cnt-n;
        while(p!=NULL)
        {
            res--;
            if(res==0)
            {
                break;
            }
            p=p->next;
        }
        ListNode*q=p->next;
        p->next=q->next;
        return head;
        
    }
};