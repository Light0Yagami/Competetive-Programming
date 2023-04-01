/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        helper(0,candidate,target,ds, ans);
        return ans;
    }

    void helper(int ind, vector<int>& candidate, int target, vector<int>& ds, vector<vector<int>>& ans){
        if(ind == candidate.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidate[ind] <= target){
            ds.push_back(candidate[ind]);
            helper(ind, candidate,target-candidate[ind],ds,ans);
            ds.pop_back();
            }

        helper(ind+1,candidate,target,ds,ans);

    }
};
