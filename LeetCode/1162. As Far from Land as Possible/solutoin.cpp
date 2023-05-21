/*

Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis = grid;
        for(int i = 0; i< n;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }

        if(q.empty() || q.size() == n *n ) return -1;

        int distance = 0;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dirs){
                    int i = x + dx;
                    int j = y + dy;

                    if(i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == 0){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
            distance++;
        }

        return distance - 1;
    }
