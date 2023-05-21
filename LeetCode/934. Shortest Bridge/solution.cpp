/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/

class Solution {
private:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<int,int>> &q,int i, int j, vector<vector<int>> &dirs){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || vis[i][j] || grid[i][j] == 0){
            return;
        }

        vis[i][j] = true;
        q.push({i,j});
        for( auto &dir : dirs){
            dfs(grid, vis, q,i + dir[0], j + dir[1] , dirs);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        bool found = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid,vis,q,i,j,dirs);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }



        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size --){
                auto cur = q.front();
                q.pop();
                for(auto &dir : dirs){
                    int i = cur.first + dir[0];
                    int j = cur.second + dir[1];
                    if(i >= 0 && j >= 0 && i < n && j < n && !vis[i][j]){
                        if(grid[i][j] == 1){
                            return step;
                        }
                        q.push({i,j});
                        vis[i][j] = true;
                    }
                }
            }
            step++;
        }

        return -1;


    }
};
