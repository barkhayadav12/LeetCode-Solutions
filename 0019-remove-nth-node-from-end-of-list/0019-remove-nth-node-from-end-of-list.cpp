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
        if(head->next==NULL)
        {
            return NULL;
        }
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        int ans=cnt-n;
        int x=0;
        ListNode*p=head;
        ListNode*q=head->next;
        if(ans==0)
        {
            p=NULL;
            head=q;
        }
        while(q!=NULL)
        {
            x++;
            if(x==ans)
            {
                p->next=q->next;
                delete q;
                q=p->next;
                break;
            }
            p=q;
            q=q->next;
        }
        return head;
        
        
    }
};