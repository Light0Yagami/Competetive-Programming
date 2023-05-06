/*
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
     int res = 0, mod = 1e9 + 7, l = 0, r = nums.size()-1;
     
     vector<int>pre = {1};
     for(int i = 0; i < nums.size(); i++){
         pre.push_back((pre.back() << 1) % mod);
     }

     sort(nums.begin(), nums.end());

     while(l <= r){
         if(nums[l] + nums[r] > target){
             r--;
         }
         else{
             res = (res + pre[r - l++])%mod;
         }
     }

     return res;   
    }
};
