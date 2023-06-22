/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

*/

class Solution {
public:

    /* Recursion + Memoisation
        
    int solve(int i, int j,vector<vector<int>>&matrix,vector<vector<int>> &dp){
        if(j < 0 || j >= matrix.size()) return 1e9;
        if(i==0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];
        int s = matrix[i][j] + solve(i-1,j,matrix,dp);
        int ll =matrix[i][j] + solve(i-1,j-1,matrix,dp);
        int nd = matrix[i][j] + solve(i-1,j+1,matrix,dp);

        return dp[i][j] = min(s,min(ll,nd));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i = 0; i < n; i++){
            mini = min(solve(n-1,i,matrix,dp),mini);
        }

        return mini;
    }

    */


    //in this code we didn't took extra dp we used the same matrix
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minVal = INT_MAX, n = matrix.size();
        int l, r, u;

        // Handle base case (For n = 1)
        if(n == 1) {
            for(auto& cell: matrix[0]) 
                minVal = min(minVal, cell);
            return minVal;
        }

        // Bottom Up Tabulation
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                l = (j > 0) ? matrix[i-1][j-1] : INT_MAX;
                r = (j < n-1) ? matrix[i-1][j+1] : INT_MAX;
                u = matrix[i-1][j];

                matrix[i][j] += min({l, r, u});

                // Find min of last row
                if(i == n-1)
                    minVal = min(minVal, matrix[i][j]);
            }
        }

        return minVal;
    }
};
   
