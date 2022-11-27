/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. 
If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        
        int i =0, j = n - 1;
        sort(nums.begin(), nums.end());
        
        int maxGap = 0;
        
        while(i < n-1){
            maxGap = max(maxGap,nums[i+1]-nums[i]);
            i++,j--;
        }
        
        
        return maxGap;
        
    }
};
