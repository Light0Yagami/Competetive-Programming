/*
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
    

    void solve(TreeNode* node, bool goLeft, int currPathLen, int &res) {
        if (!node) return;
        res = max(res, currPathLen);
        if (goLeft) {
            solve(node->left, false, currPathLen + 1,res);
            solve(node->right, true, 1,res);
        } else {
            solve(node->right, true, currPathLen + 1,res);
            solve(node->left, false, 1,res);
        }
    }

    int longestZigZag(TreeNode* root) {
        int res = 0;
        solve(root, true, 0, res);
        solve(root, false, 0,res);
        return res;
    }
};
