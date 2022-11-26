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
                q.push({(temp.first)->left,temp.second+1}); //for left view just right this conditon first
            }
            
        }
        
        
        return ans;
    }
};


// Also you can use recursion to reduce space complexity

 vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int lvl = 1;
        int maxlvl = 0;
        helper(ans,root,lvl,maxlvl);
        return ans;
    }
    
    void helper(vector<int> &ans, TreeNode *root, int level, int &maxlvl){
        if(!root) return;
        
        if(maxlvl < level){
            ans.push_back(root->val);
            maxlvl = level;
        }
        
        helper(ans,root->right,level + 1,maxlvl);
        helper(ans,root->left,level + 1, maxlvl);
    } 
