/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

*/

class Solution {
public:

    /*                         RECURSION


    int solve(int ind, vector<int> &nums){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        int picked = solve((ind - 2), nums) + nums[ind];

        int notpicked = solve((ind - 1),nums);

        return max(picked,notpicked);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1,nums);        
    }
    */

    /*                         MEMOMISATION


    int solve(int ind, vector<int> &nums,vector<int> &dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];
        int picked = solve((ind - 2), nums,dp) + nums[ind];

        int notpicked = solve((ind - 1),nums,dp);

        return dp[ind] = max(picked,notpicked);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);        
    }

    */

    /*                          TABULIZED 

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int picked = 0, notpicked = 0;
        for(int i = 1; i < n ; i++){
            picked = nums[i];

            if(i > 1) picked += dp[i -2];

            notpicked = dp[i - 1];
            dp[i] = max(picked, notpicked);
        }     

        return dp[n-1];
    }

    */

    /*                SPACE OPTIMIZATON
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int prev = nums[0];
        int prev2 = 0;
        int picked = 0, notpicked = 0;
        for(int i = 1; i < n ; i++){
            picked = nums[i];
            if(i > 1) picked += prev2;

            notpicked = prev;

            int cur = max(picked, notpicked);

            prev2 = prev;
            prev = cur;
        }     

        return prev;
    }
};
