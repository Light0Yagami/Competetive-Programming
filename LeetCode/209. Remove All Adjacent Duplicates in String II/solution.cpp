/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stack;
        
        for(int i = 0; i< s.length(); i++){
            if(stack.empty() || stack.top().first != s[i]){
                stack.push({s[i],1});
            }
            else{
                auto prev = stack.top();
                stack.pop();
                stack.push({s[i],prev.second + 1});
            }
            if(stack.top().second == k) stack.pop();
        }   

        string ans = "";
        while(!stack.empty()){
            auto cur = stack.top();
            stack.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;



        
    }
