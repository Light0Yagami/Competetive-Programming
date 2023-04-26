/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        
        string s(n,'.');
        vector<string> board(n,s);
        map<int, bool> row_,diag1,diag2;
        solve(0,board,count,n,row_,diag1,diag2);
        

        return count;
    }

    void solve(int col, vector<string>& board, int& count, int n, map<int,bool> &row_, map<int,bool> &diag1, map<int,bool> &diag2){
        if(col == n){
            count++;
        }
        
        for(int row = 0; row < n; row++){
            if(isSafe(row,col,row_,diag1,diag2,n)){
                board[row][col] = 'Q';
                row_[row] = true;
                diag1[row + col] = true;
                diag2[(n-1) + col - row] = true;
                solve(col+1,board,count,n,row_,diag1,diag2);
                row_[row] = false;
                diag1[row + col] = false;
                diag2[(n-1) + col - row] = false;
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, map<int,bool> &row_, map<int,bool> &diag1, map<int,bool> &diag2,int n){
        if(row_[row] == true || diag1[row + col] == true || diag2[(n-1) + col - row] == true){
            return false;
        }
        return true;
    }


};
