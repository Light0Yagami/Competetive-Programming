/*Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp,n);
        
        return ans;
    }

    void solve(int index, string s, vector<vector<string>> &ans, vector<string>& temp , int n){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < n; i++){
            if(isPalindrome(s, index, i)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,temp,n);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int i , int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
