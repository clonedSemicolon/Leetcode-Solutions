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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<vector<TreeNode*>>q;
        vector<TreeNode*>v;
        v.push_back(root);
        q.push(v);
        
        vector<vector<int>>res;
        while(!q.empty()){
            vector<TreeNode*> cr = q.front();
            q.pop();
            vector<int>vc;
            int i = 0;
            int j = cr.size();
            // cout<<cr.size()<<endl;
            vector<TreeNode*>nxt;
            while(i<j){
                if(cr[i]){
                    vc.push_back(cr[i]->val);
                    nxt.push_back(cr[i]->left);
                    nxt.push_back(cr[i]->right);
                }
                
                i++;
            }
            
            if(nxt.size()){
                q.push(nxt);
                res.push_back(vc);
            }
        }
        
        return res;
    }
};