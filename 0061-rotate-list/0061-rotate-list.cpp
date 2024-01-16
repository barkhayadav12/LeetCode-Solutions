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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
        {
            return head;
        }
        ListNode*tail=head;
        int len=1;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }
        if(k%len==0)
        {
            return head;
        }
        k=k%len;
        tail->next=head;
        int cnt=0;
        int r=len-k;
        ListNode*temp=head;
        while(temp!=NULL)
        {
             cnt++;
            if(cnt==r)
            {
                head=temp->next;
                temp->next=NULL;
            }
            temp=temp->next;
        }
        return head;
        
    }
};