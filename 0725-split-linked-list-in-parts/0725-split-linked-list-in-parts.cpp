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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int nodes=0;
        ListNode*temp=head;
        vector<int>vec;
        while(temp!=NULL)
        {
            nodes++;
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int parts=0;
        int rem=0;
        int sz=k;
        if(nodes<=k)
        {
            parts=1;
            sz=nodes;
        }
        else{
            parts=nodes/k;
            rem=nodes%k;
        }
        vector<vector<int>>v(sz,vector<int>(parts,0));
        for(int i=0;i<rem;i++)
        {
            v[i].push_back(0);
        }
        int p=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                v[i][j]=vec[p];
                p++;
            }
        }
        vector<ListNode*>ans;
        for(int i=0;i<v.size();i++)
        {
            ListNode*nodes=new ListNode(-1);
            ListNode*temp=nodes;
            for(int j=0;j<v[i].size();j++)
            {
                ListNode*newNode=new ListNode(v[i][j]);
                temp->next=newNode;
                temp=newNode;
            }
            ans.push_back(nodes->next);
        }
        if(ans.size()!=k)
        {
            ListNode*temp=NULL;
            int r=k-ans.size();
            for(int i=0;i<r;i++)
            {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};