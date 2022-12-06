/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix.size() - 1;

        while(r < matrix.size() and c >= 0 ){
            if(matrix[r][c] == target){
                return true;
            }

            if(matrix[r][c] < target){
                r++;
            }else{
                c--;
            }
        }
        return false;
    }
};
