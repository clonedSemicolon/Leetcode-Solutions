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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            if(!root)
                return {};
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                TreeNode* now = q.front();
                q.pop();
                if(i==sz-1){
                    ans.push_back(now->val);
                }
                
                if(now->left)
                    q.push(now->left);
                if(now->right)
                    q.push(now->right);
            }
        }
        
        return ans;
        
    }
};