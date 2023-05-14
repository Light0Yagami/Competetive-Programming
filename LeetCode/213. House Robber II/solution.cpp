/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:

    int solve(vector<int>& nums) {
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


    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n = nums.size();

        if(n == 1) return nums[0];        
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1),solve(temp2));
    }
};
