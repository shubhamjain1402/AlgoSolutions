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
    TreeNode* bfsToMapParents(TreeNode* root ,unordered_map <TreeNode*,TreeNode*> &mpp,int start){
        queue <TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node -> val == start)   res=node;
            q.pop();
            if(node -> left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node -> right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int findDistance(unordered_map <TreeNode*,TreeNode*> &mpp , TreeNode* target){
        queue <TreeNode*> q;
        q.push(target);
        map <TreeNode*,int > visited;
        visited[target]=1;
        int maxi=0;
        while(!q.empty()){
            int size=q.size();
            int fl=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    fl=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    fl=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(mpp[node] && !visited[mpp[node]]){
                    fl=1;
                    visited[mpp[node]]=1;
                    q.push(mpp[node]);
                }
            }
            if(fl) maxi++;  
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map <TreeNode*,TreeNode*> mpp;
        TreeNode* target=bfsToMapParents(root,mpp,start);
        int maxi=findDistance(mpp,target);
        return maxi;
    }
};