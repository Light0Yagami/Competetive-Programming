/*
Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.
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

    unordered_map<int,vector<TreeNode*>>mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return{};
        }
        
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        vector<TreeNode*> result;
        for(int i = 1; i <n; i += 2){
            vector<TreeNode*> leftFBT = allPossibleFBT(i);
            vector<TreeNode*> rightFBT = allPossibleFBT(n-1-i);

            for(auto &l : leftFBT){
                for(auto &r: rightFBT){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return mp[n] = result;
    }


};
