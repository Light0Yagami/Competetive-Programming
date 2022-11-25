/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the 
nodes you can see ordered from top to bottom.
*/

//APPROACH : Store level whenever you vist;


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
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level = -1;
        
        while(!q.empty()){
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            
            if(temp.second > level){
                ans.push_back((temp.first)->val);
                level++;
            }
            
            if(temp.first->right){
                q.push({(temp.first)->right,temp.second+1});
            }
            if(temp.first->left){
                q.push({(temp.first)->left,temp.second+1});
            }
            
        }
        
        
        return ans;
    }
};
