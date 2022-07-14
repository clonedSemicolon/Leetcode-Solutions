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
    TreeNode* solve(int pre, int st, int end, vector<int>& preorder, vector<int>& inorder){
        if (st>end || pre>preorder.size()-1)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre]);
        int val = 0;
        for(int i = st;i<=end;i++){
            if(root->val == inorder[i])
                val = i;
        }
        
        root->left = solve(pre+1,st,val-1,preorder,inorder);
        root->right = solve(pre+val-st+1,val+1,end,preorder,inorder);
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,0,inorder.size()-1,preorder,inorder);
    }
};