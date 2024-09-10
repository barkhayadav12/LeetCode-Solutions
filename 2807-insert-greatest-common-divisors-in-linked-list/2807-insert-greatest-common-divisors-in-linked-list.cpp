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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>res;
        for(int i=0;i<v.size()-1;i++)
        {
            res.push_back(v[i]);
            res.push_back(__gcd(v[i],v[i+1]));
        }
        res.push_back(v[v.size()-1]);
        ListNode*p=new ListNode(-1);
        ListNode*q=p;
        for(int i=0;i<res.size();i++)
        {
            ListNode*temp=new ListNode(res[i]);
            q->next=temp;
            q=temp;
        }
        return p->next;
    }
};