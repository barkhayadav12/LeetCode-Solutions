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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        multiset<int>st;
        for(auto it:nums)
        {
            st.insert(it);
        }
        ListNode*ans=new ListNode(0);
        ListNode*p=ans;
        for(auto it:v)
        {
            if(st.find(it)==st.end())
            {
                ListNode*temp=new ListNode(it);
            temp->next=NULL;
            p->next=temp;
            p=temp;
            }
        }
        return ans->next;
    }
};