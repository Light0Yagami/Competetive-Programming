/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         // Create a set...
        unordered_set<int> hset;
        // Traverse all the elements through the loop...
        for(int idx = 0; idx < nums.size(); idx++) {
            // Searches set. if present, it contains duplicate...
            if(hset.count(nums[idx]))
                return true;
            // insert nums[i] in set...
            hset.insert(nums[idx]);
        }
        return false;
    }
};
