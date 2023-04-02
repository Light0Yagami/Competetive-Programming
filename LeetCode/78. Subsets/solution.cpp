/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        helper(0,nums,ans,ds);

        return ans;        
    }

    void helper(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> &ds){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);

        helper(i+1,nums,ans,ds);
        ds.pop_back();

        helper(i+1,nums,ans,ds);

    }
};
