/*
Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.

Since the answer may be very large, return it modulo 109 + 7.
  */


class Solution {
private:
    vector<vector<long long>> table;
    long long dfs(vector<int> &nums,long long mod){
        int n = nums.size();
        if(n <= 2) return 1;

        //find left subsequence
        vector<int> left, right;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        //recursion
        long long left_res = dfs(left,mod) % mod;
        long long right_res = dfs(right,mod) % mod;

        //look up table
        int left_len = left.size(), right_len = right.size();
        return (((table[n-1][left_len] * left_res) % mod) * right_res) % mod;

    }

public:
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9+ 7;
        int n = nums.size();

        table.resize(n+1);
        for(int i = 0; i < n +1; ++i){
            table[i] = vector<long long> (i +1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }

        long long ans = dfs(nums, mod);
        return (ans % mod -1)%mod;  // one way is in question itself
    }
};
