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
    TreeNode* build(vector<int>&pre,vector<int>&ino, int start, int end,int &idx){
            // idx hmesa preoder ke liye hai
            if(start>end){return NULL;}

            int val=pre[idx];
            idx++;
            int i=start;
            for(;i<=end;i++){
                if(val==ino[i])
                {
                  break;
                }
            }
            TreeNode* root=new TreeNode(val);
            root->left=build(pre,ino,start,i-1,idx);
            root->right=build(pre,ino,i+1,end,idx);
            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n=preorder.size();
       int idx=0;
       return build(preorder,inorder,0,n-1,idx);
    }
};
