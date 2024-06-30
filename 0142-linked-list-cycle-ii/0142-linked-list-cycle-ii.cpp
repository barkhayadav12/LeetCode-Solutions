/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode*>mpp;
        // ListNode*p=head;
        // ListNode*ans=NULL;
        // while(p!=NULL)
        // {
        //     if(mpp.find(p)!=mpp.end())
        //     {
        //         ans=p;
        //         break;
        //     }
        //     mpp.insert(p);
        //     p=p->next;
        // }
        // return ans;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                slow=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};