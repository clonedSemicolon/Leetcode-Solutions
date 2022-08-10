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
    
    TreeNode* construct(vector<int>& nums,int left,int right){
        if(left>right) return NULL;
        int m = (left+right)/2;
        TreeNode* nd = new TreeNode(nums[m]);
        nd -> left = construct(nums,left,m-1);
        nd -> right = construct(nums,m+1,right);
        return nd;
    }
    
TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        return construct(nums,0,nums.size()-1);
}
};