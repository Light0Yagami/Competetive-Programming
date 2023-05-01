/*
Given the root of a n-ary tree find the number of duplicate subtrees in the n-ary tree. Two trees are duplicates if they have the same structure with the same node values.
*/
unordered_map<string,int> map;

string solve(Node *root){
        string temp = to_string(rood->data);
        for(auto x: root->children){
            string t = solve(x);
            temp = temp + t + "*";
        }
        map[temp]++;
        return temp;
    }
    
    int duplicateSubtreeNaryTree(Node *root){
        map.clear();
        solve(root);
        
      int ans = 0;
        for(auto x : map){
            if(x.second > 1) ans++;
        }
      return ans;
    }
     
