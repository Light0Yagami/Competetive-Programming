/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

*/

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
