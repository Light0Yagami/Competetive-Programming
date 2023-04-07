/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int freq[n];
        for(int i = 0; i<n; i++) freq[i] = 0;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        permutation(nums,ans,ds,freq);


        return ans;
    }
    void permutation(vector<int>& nums,vector<vector<int>>& ans, vector<int>& ds,int freq[]){
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return;
            }

            for(int i = 0; i < nums.size(); i++){
                if(!freq[i]){
                    ds.push_back(nums[i]);
                    freq[i] = 1;
                    permutation(nums,ans,ds,freq);
                    freq[i] = 0;
                    ds.pop_back();
                    while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
                }
            }
        }
};
