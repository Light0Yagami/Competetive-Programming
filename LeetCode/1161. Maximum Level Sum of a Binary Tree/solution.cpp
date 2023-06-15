/*Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans = 0;
        int maxSum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* cur = q.front();
                q.pop();

                sum += cur->val;
                
                if(cur->left != NULL){
                    q.push(cur->left);
                }
                
                if(cur->right != NULL){
                    q.push(cur->right);
                }
                
            }

            if(sum > maxSum){
                ans = level;
                maxSum = sum;
            }
            level++;
        }
        return ans;
    }
};
