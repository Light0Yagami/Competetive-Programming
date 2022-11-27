/*
Given an integer array nums, find the subarray which has the largest sum and return its sum.
*/

// APPORACH : Kadanes Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int cursum = 0;
        
        for(int i = 0; i< nums.size(); i++){
            
            cursum += nums[i];
            
            maxsum = max(maxsum,cursum);
            
            if(cursum < 0){
                cursum = 0;
            }
            
        }
        
        
        return maxsum;
    }
};
