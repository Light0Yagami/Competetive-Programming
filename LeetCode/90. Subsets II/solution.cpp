/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        help(0,nums,ans,ds);

        return ans;        
    }

    void help(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> &ds){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        help(i+1,nums,ans,ds);
        
        ds.pop_back();
        while(i+1 <nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        help(i+1,nums,ans,ds);

    }
};
