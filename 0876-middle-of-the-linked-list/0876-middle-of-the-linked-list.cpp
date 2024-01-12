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
    ListNode* middleNode(ListNode* head) {
        ListNode*p=head;
        int cnt=0;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        int mid=0;
        if(cnt%2==0)
        {
            mid=floor(cnt/2);
        }
        else{
            mid=ceil(cnt/2);
        }
        ListNode*q=head;
        int ans=0;
        while(q!=NULL)
        {
            if(ans==mid)
            {
                head=q;
                break;
            }
            q=q->next;
            ans++;
        }
        return head;
    }
};