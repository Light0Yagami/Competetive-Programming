/*
Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive elements in the array, at least one of the elements is present in our subset. 
*/
 long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(N,vector<long long>(2,-1));
        return solve(0,A,N,1,dp);
    }
    
    long long solve(int ind, vector<int> &A, int n,int indicator,vector<vector<long long>> &dp){
        if(ind == n) return 0;
        
        if(dp[ind][indicator] != -1) return dp[ind][indicator];
        long long a = INT_MIN,b = INT_MIN;
        if(indicator == 1){
            b = solve(ind+1,A,n,0,dp);
        }
        
        a = A[ind] + solve(ind + 1,A,n,1,dp);
        
        return dp[ind][indicator] = max(a,b);
    }
    
