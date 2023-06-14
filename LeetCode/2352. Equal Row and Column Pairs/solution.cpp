/*Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 
*/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        map<vector<int>,int>mp;

        for(int i = 0; i < grid[0].size(); i++){
            mp[grid[i]]++;
        }

        for(int j = 0; j < grid[0].size(); j++){
            vector<int>v;
            for(int i = 0; i < grid.size(); i++){
                v.push_back(grid[i][j]);
            }

            ans += mp[v];
        }

        return ans;
    }
};
