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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*p=head->next;
        ListNode*q=head;
        vector<int>ans;
        int cnt=1;
        while(p->next!=NULL)
        {
            cnt++;
            ListNode*temp=p->next;
            if((p->val>q->val && p->val>temp->val) || (p->val<q->val && p->val<temp->val))
            {
                ans.push_back(cnt);
            }
            q=p;
            p=p->next;
        }
        if(ans.size()<2)
        {
            return {-1,-1};
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        int maxi=ans[n-1]-ans[0];
        int mini=INT_MAX;
        for(int i=1;i<ans.size();i++)
        {
            mini=min(mini,ans[i]-ans[i-1]);
        }
        vector<int>res={mini,maxi};
        return res;
    }
};