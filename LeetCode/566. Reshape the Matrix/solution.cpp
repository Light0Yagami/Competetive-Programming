/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int r0 = mat.size(), c0 = mat[0].size();
        if (r0*c0 != r*c) return mat;

        vector<int> v0(c);
        vector<vector<int>> v(r, v0);

        // this is a approach to reduce the no of lines of code
        // as i iterates through 0 to r*c, dividing i by column would get you               the row number
        // and the remainder would give you the current column number
        for (int i=0; i<r0*c0; ++i) {
            v[i/c][i%c] = mat[i/c0][i%c0];
        }

        return v;
    }
};
