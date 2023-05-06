/*

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

*/

void solve(int i, int j, vector<vector<int>> &m,int n, vector<vector<int>> &vis,vector<string> &ans,string path,int di[], int dj[]){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        
        string dir = "DLRU";
        for(int ind = 0; ind < 4; ind++){
            int newi = i + di[ind];
            int newj = j + dj[ind];
            if(newi >= 0 && newj >= 0 && newi < n && newj < n && !vis[newi][newj] && m[newi][newj] == 1){
                vis[i][j] = 1;
                solve(newi,newj,m,n,vis,ans,path + dir[ind],di,dj);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        int di[4] = {1,0,0,-1};
        int dj[4] = {0,-1,1,0};
        
        solve(0,0,m,n,vis,ans,"",di,dj);
        
        if(ans.size() == 0){
            ans.push_back("-1");
        }
        
        return ans;
    }
