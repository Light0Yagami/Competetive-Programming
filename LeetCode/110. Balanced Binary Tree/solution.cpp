/*
Given a binary tree, determine if it is height-balanced.
*/

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
    bool isBalanced(TreeNode* root) {
        int i = check(root);
        if(i == -1){
            return false;
        }
        
        return true;
    }
    
    int check(TreeNode *root){
        if(root == NULL) return 0;
        
        int left = check(root->left);
        
        if(left == -1) return -1; 
        
        int right = check(root->right);
        
        if(right == -1 || abs(right - left) > 1) return -1;
        
        return max(left,right) + 1;
        
    }
};
