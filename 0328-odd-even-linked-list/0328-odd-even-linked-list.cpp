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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*k=new ListNode(head->val);
        k->next=NULL;
        ListNode*ans=k;
        ListNode*p=head;
        p=p->next;
        int cnt=2;
        while(p!=NULL)
        {
            if(cnt%2==1)
            {
                ListNode*temp=new ListNode(p->val);
                temp->next=NULL;
                ans->next=temp;
                ans=temp;
            }
            p=p->next;
            cnt++;
        }
        ListNode*q=head;
        q=q->next;
        int cntEven=2;
        while(q!=NULL)
        {
            if(cntEven%2==0)
            {
                ListNode*temp=new ListNode(q->val);
                temp->next=NULL;
                ans->next=temp;
                ans=temp;
            }
            q=q->next;
            cntEven++;
        }
        return k;
        
        
    }
};