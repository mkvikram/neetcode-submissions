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
    int solve(TreeNode* root,int maxSofar)
    {
        if(!root){return 0;}
        
        int count=0;
        if(root->val>=maxSofar){
           count=1;
           maxSofar=root->val;
        }
        count+=solve(root->left,maxSofar);
        count+=solve(root->right,maxSofar);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){return 0;}
        if(root->left==nullptr && root->right==nullptr)
        {
            return 1;
        }
        return solve(root,INT_MIN);// root,maximumsofar
    }
};
