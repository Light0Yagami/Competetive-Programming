/*
You are given a binary string s consisting only of zeroes and ones.

A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return the length of the longest balanced substring of s.

A substring is a contiguous sequence of characters within a string.
*/
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n;){
            int c1 = 0, c0 =0;
            while(i < n && s[i] == '0')
            {
                c0++;
                i++;
            }
            while(i < n && s[i] == '1'){
                c1++;
                i++;
            }
            int len =2* min(c0,c1);
            ans = max(ans,len);

        }
        return ans;
    }
};
