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
    bool isValidBST(TreeNode* root) {
        return ValidBST(root , LONG_MIN, LONG_MAX);
    }
    bool ValidBST(TreeNode* root , long minval ,long maxval){
        if(root == NULL)    return true;
        if(root -> val >= maxval || root->val <=minval) return false;
        return ValidBST(root->left,minval,root->val) 
        && ValidBST(root->right,root->val,maxval);
    }
};