/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return{{"Q"}};
        
        string s(n,'.');
        vector<string> v(n,s);
        
        
        fun(0,n,v);
        return  ans;  
    }
    void fun(int col,int n,vector<string> &v)
    {
        if(col==n) {
            ans.push_back(v);
            return;
        }
        for(int r=0;r<n;r++)
            if(okTogo(r,col,n,v))
            {
                v[r][col]='Q';
                fun(col+1,n,v);
                v[r][col]='.';
            }
    }

    bool okTogo(int r,int c,int n,vector<string> &v)
    {
        int row =r,col =c;
        
        //digonal check uppr left
        while(r>=0 && c>=0)
        {
            if(v[r][c]=='Q') return false;
            r--;c--;
        }
        // lower left diagonal
        r=row;c=col;
        while(r<n && c>=0)
        {
            if(v[r][c]=='Q') return false;
            r++;c--;
        }
        
         //check horizontal left side
        while(col>=0)
        {
            if(v[row][col]=='Q') return false;
            col--;
        }
        return true;
    }


};
