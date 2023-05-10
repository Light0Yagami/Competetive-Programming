/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int left = 0, right = n -1;
        int top = 0, bottom = n -1;
        int i,count = 1;
        while(count <= n*n){
            for(i = left; i <= right; i++){
                matrix[top][i] = count++;
            }top++;

            for(i = top; i <= bottom; i++){
                matrix[i][right] = count++;
            }right--;

            for(i = right; i >= left; i--){
                matrix[bottom][i] = count++;
            }bottom--;

            for(i = bottom; i>= top; i--){
                matrix[i][left] = count++;
            }left++;

        }

        return matrix;
    }
};
