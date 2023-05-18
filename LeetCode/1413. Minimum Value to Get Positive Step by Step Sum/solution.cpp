/*
Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.
*/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int  i = 1;
        for(int i = 1; i< nums.size(); i++)
            nums[i] += nums[i-1];
        
        int mini = *min_element(nums.begin(),nums.end());
        return ((mini < 0))? abs(mini)+1:1;
    }
};
