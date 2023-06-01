/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 0 || grid[0][0] != 0)
            return -1;

        auto isSafe = [&](int x, int y){
            return  x >= 0 &&  x < n && y >= 0 && y < n;
        };


        vector<vector<int>> dirs = {{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int level = 1;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                if(x == n - 1 && y == n - 1){
                    return level;
                }

                for(auto dir : dirs){
                    int i = x + dir[0];
                    int j = y + dir[1];

                    if(isSafe(i,j) && grid[i][j] == 0){
                        q.push({i,j});
                        grid[i][j] = 1;
                    }
                }


            }

            level++;
        }
        return -1;
    }
};
