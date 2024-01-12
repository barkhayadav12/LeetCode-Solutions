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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
        {
            head=NULL;
            return head;
        }
        int cnt=0;
        ListNode*p=head;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        int mid;
        if(cnt%2==0)
        {
            mid=floor(cnt/2);
        }
        else{
            mid=ceil(cnt/2);
        }
        int ans=0;
        ListNode*x=NULL;
        ListNode*q=head;
        while(q!=NULL)
        {
            if(ans==mid)
            {
                x->next=q->next;
                delete q;
                q=x->next;
                break;
            }
            x=q;
            q=q->next;
             ans++;
            
        }
        return head;
        
    }
};