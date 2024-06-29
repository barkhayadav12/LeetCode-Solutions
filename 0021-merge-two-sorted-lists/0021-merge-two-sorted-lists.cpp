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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p=list1;
        ListNode*q=list2;
        ListNode*head=new ListNode();
        ListNode*temp=head;
        while(p!=NULL && q!=NULL)
        {
            int val1=p->val;
            int val2=q->val;
            if(val1>val2)
            {
                temp->next=q;
                q=q->next;
            }
            else
            {
                temp->next=p;
                p=p->next;
            }
            temp=temp->next;
        }
        if(p!=NULL)
        {
            temp->next=p;
        }
        if(q!=NULL)
        {
            temp->next=q;
        }
        return head->next;
    }
};