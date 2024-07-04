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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        ListNode*p=head->next;
        int sum=0;
        while(p!=NULL)
        {
            if(p->val!=0)
            {
                int num=p->val;
                sum+=num;
            }
            else{
                ListNode*newNode=new ListNode(sum);
                sum=0;
                temp->next=newNode;
                newNode->next=NULL;
                temp=temp->next;
            }
            p=p->next;
        }
        return dummyNode->next;
    }
};