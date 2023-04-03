/*
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxit = INT_MIN;
        for(int i : nums) {
            map[i]++;
            maxit = max(map[i],maxit);
        }

        vector<vector<int>> matrix;

        while(maxit != 0){
            vector<int> row;
            for(auto it: map){
                
                if(it.second != 0) {
                    row.push_back(it.first);
                    map[it.first]--;
                }
            }
            matrix.push_back(row);
            maxit--;
        }
        

        return matrix;
    }
};
