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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* node = root;
        TreeNode* newnode = new TreeNode(val);
        while(node -> left != NULL || node -> right != NULL){
            if(node -> val > val) node=node->left;
            else    node=node->right;
        }
        if(node -> val < val)   node->right=newnode;
        else    node->left=newnode;
        return root;
    }
};