/*You are given a string str of length n. You want to choose a non-zero integer k (k<=n), such that you can perform the following operation:
Take the prefix of the string of length k and append the reverse of it to itself.
Your task is to find the lexicographically smallest string you can get.
*/

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string temp = "";
        temp += str[0];
        for(int i = 1; i < str.length(); i++){
            if(str[i] < temp[i -1]) temp += str[i];
            else if(str[i] == temp[i-1] and i != 1) temp += str[i];
            else break;
        }
        
        string ans = temp;
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }
};
