/*

You are given an array A of N integers and an integer K, and your task is to find the total number of cuts that you can make such that for each cut these two conditions are satisfied
1. A cut divides an array into two parts equal or unequal length (non-zero).
2. Sum of the largest element in the left part and the smallest element in the right part is greater than or equal to K.

*/

class Solution{
public:
    int totalCuts(int n,int K,vector<int> &A){
        // Code here
        int count = 0;
        
        vector<int> prefix;
        vector<int> suffix(n,0);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            maxi  = max(maxi,A[i]);
            prefix.push_back(maxi);
        }
        
        for(int i = n-1; i >= 0; i--){
            mini=  min(mini,A[i]);
            suffix[i] = mini;
        }
        
        for(int i = 0;i  < n - 1; i++){
            if(prefix[i] + suffix[i+1] >= K){
                count++;
            }
        }
        
        
        return count;
    }
};
