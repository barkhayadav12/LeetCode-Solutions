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
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int total_node=1;
        ListNode*temp=head;
        while(temp->next!=NULL)
        {
            total_node++;
            temp=temp->next;
        }
        ListNode*tail=temp;
        if(k%total_node==0)
        {
            return head;
        }
        k=k%total_node;
        int reqd=total_node-k;
        tail->next=head;
        temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==reqd)
            {
                head=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};