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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        ListNode*p=head;
        ListNode*q=head->next;
        bool flag=false;
        while(1)
        {
            ListNode*newNode=new ListNode();
            newNode->val=q->val;
            newNode->next=NULL;
            temp->next=newNode;
            temp=temp->next;
            ListNode*newSecondNode=new ListNode();
            newSecondNode->val=p->val;
            newSecondNode->next=NULL;
            newNode->next=newSecondNode;
            temp->next=newSecondNode;
            temp=temp->next;
            if(q->next==NULL)
            {
                break;
            }
            if(q->next->next==NULL)
            {
                flag=true;
                break;
            }
            p=q->next;
            q=p->next;
        }
        if(flag)
        {
            q=q->next;
            ListNode*newNode=new ListNode(q->val);
            newNode->next=NULL;
            temp->next=newNode;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};