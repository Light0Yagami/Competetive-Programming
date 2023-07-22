/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.
*/

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    unordered_map<string,double> mp;

    double solve(int n, int moves, int row, int column){
        if(row < 0 || row >= n || column < 0 || column >= n)
            return 0;
        
        if(moves == 0)
            return 1;
        
        string key = to_string(row) + "_" + to_string(column) + "_" + to_string(moves);

        if(mp.find(key) != mp.end())
            return mp[key];

        double prob = 0;
        for(auto dir : dirs){
            int new_r = row + dir.first;
            int new_c = column + dir.second;

            prob += solve(n, moves - 1, new_r, new_c)/8.0;
        }

        return mp[key] = prob;
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);    
    }
};
