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
      int mans=INT_MIN;
      int dfs(TreeNode* root){
        if(root==NULL){return 0;}
        int left=max(0,dfs(root->left));
        int right=max(0,dfs(root->right));
        int  ans=left+right+root->val;   
        mans=max(mans,ans);    
        return max(root->val,root->val+max(left,right));
    } ;
    int maxPathSum(TreeNode* root) {
        /*
        Kisi bhi node par khade ho kar, tere paas 3 choices hain:

Main sirf apne aap ko loon.

Main apne aap ko + left side ka path loon.

Main apne aap ko + right side ka path loon.

Main apne aap ko + left + right (Yahan Path khatam ho jayega aur ye "peak" ban jayega).
        */
        dfs(root);
        return mans;
    }
};
