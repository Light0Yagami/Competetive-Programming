/*
You are given a root node of a binary Tree and each node of the binary tree is assigned a value and you are also given an integer k and you have to return the count of Good subtrees of this binary Tree . Good subtree is a subtree such that the number of distinct values in this subtree is less than or equal to k.

Note: Subtree of a node consists of that node and all nodes of the subtrees of left and right child  of that node  if they exist .
*/

class Solution{
public:
    
    set<int> solve(Node *root, int k, int &ans){
        if(root == NULL) return {};
       
        set<int> s, sl, sr;
        sl = solve(root->left,k,ans);
        sr = solve(root->right,k,ans);
        
        if(sl.size() > k) return sl;
        if(sr.size() > k) return sr;
        
        s.insert(root->data);
        s.insert(sl.begin(),sl.end());
        s.insert(sr.begin(),sr.end());
        
        if(s.size() <= k) ans++;
        
        return s;
        
    }

    int goodSubtrees(Node *root,int k){
        // Code here
        int ans = 0;
        solve(root,k,ans);
        
        return ans;
    }
