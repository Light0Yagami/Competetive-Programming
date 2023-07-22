/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/

class Solution {
public:
/*
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return true;

        if(ind == 0) return nums[0] == target;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTake = solve(ind - 1, target, nums,dp);
        bool take = false;
        if(target >= nums[ind])
            take = solve(ind-1,target-nums[ind], nums,dp);

        return dp[ind][target] = take || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i: nums){
            sum += i;
        }    
        vector<vector<int>>dp(n,vector<int>(sum/2 + 1,-1));
        if(sum % 2 != 0) return false;

        return solve(n-1,sum/2,nums,dp);
    }
*/
    
    bool canPartition(vector<int>& arr) {
        int totSum=0, n = arr.size();
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=k)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }
        return dp[n-1][k];
    }
     
    }
};
