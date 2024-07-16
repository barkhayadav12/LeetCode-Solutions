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
    bool findPath(TreeNode*root,int startValue,string &str)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==startValue)
        {
            return true;
        }
        
        //explore left
        str.push_back('L');
        if(findPath(root->left,startValue,str)==true)
        {
            return true;
        }
        str.pop_back();
        
        //explore right
        str.push_back('R');
        if(findPath(root->right,startValue,str)==true)
        {
            return true;
        }
        str.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string src="";
        string dest="";
        findPath(root,startValue,src);
        findPath(root,destValue,dest);
        int i=0;
        int j=0;
        while(i<src.length() && j<dest.length())
        {
            if(src[i]!=dest[j])
            {
                break;
            }
            i++;
            j++;
        }
        string res="";
        for(;i<src.length();i++)
        {
            res+='U';
        }
        for(;j<dest.length();j++)
        {
            res+=dest[j];
        }
        return res;
    }
};