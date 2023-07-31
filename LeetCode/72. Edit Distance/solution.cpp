/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

class Solution {
public:
    int m, n;
    int t[501][501];
    int solve(int i, int j, string &word1, string &word2)
    {
        if(i == m){
            return t[i][j] = n-j;
        }
        if(j == n){
            return t[i][j] = m - i;
        }

        if(word1[i] == word2[j]) return t[i][j] = solve(i+1,j+1,word1,word2);

        if(t[i][j] != -1) return t[i][j];

        int insert = 1 + solve(i,j+1,word1,word2);
        int del = 1 + solve(i+1,j,word1,word2);
        int replace = 1 + solve(i+1,j+1,word1,word2);

        return t[i][j] = min(insert,min(del,replace));
    }

    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();

        memset(t, -1, sizeof(t));

        return solve(0,0,word1,word2);
    }
};
