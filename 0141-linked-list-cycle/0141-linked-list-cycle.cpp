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
    bool hasCycle(ListNode *head) {
        ListNode*p=head;
        unordered_set<ListNode*>mpp;
        while(p!=NULL)
        {
            if(mpp.find(p)!=mpp.end())
            {
                return true;
            }
            mpp.insert(p);
            p=p->next;
            
        }
        return false;
        
    }
};