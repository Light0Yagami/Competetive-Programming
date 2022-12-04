/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         set<string> s;
        int i,j;
        
        for(i = 0; i< 9; i++){
            for(j = 0; j < 9; j++){
                
                if(board[i][j] != '.'){
                    string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string((i/3) * 3 + (j/3))+board[i][j];

                    if(s.find(row) == s.end() && s.find(col) == s.end() && s.find(box) == s.end()){
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
