/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //node, index
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxi=0;
        while(!q.empty())
        {
            int leftmost=q.front().second;
            int rightmost=q.back().second;
            maxi=max(maxi,rightmost-leftmost+1);
            int n=q.size();
            while(n--)
            {
                auto it=q.front();
                q.pop();
                TreeNode*node=it.first;
                int i=it.second;
                if(node->left)
                {
                    q.push({node->left,2LL*i+1});
                }
                if(node->right)
                {
                    q.push({node->right,2LL*i+2});
                }
            }
        }
        return maxi;
    }
};