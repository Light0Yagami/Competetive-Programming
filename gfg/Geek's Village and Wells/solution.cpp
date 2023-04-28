/*
Geek's village is represented by a 2-D matrix of characters of size n*m, where

H - Represents a house
W - Represents a well
. - Represents an open ground
N - Prohibited area(Not allowed to enter this area)

Every house in the village needs to take water from a well, as the family members are so busy with their work, so every family wants to take the water from a well in minimum time, which is possible only if they have to cover as less distance as possible. Your task is to determine the minimum distance that a person in the house should travel to take out the water and carry it back to the house.

A person is allowed to move only in four directions left, right, up, and down. That means if he/she is the cell (i,j), then the possible cells he/she can reach in one move are (i,j-1),(i,j+1),(i-1,j),(i+1,j), and the person is not allowed to move out of the grid.

*/
class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W'){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        
        while(q.size()){
            auto temp = q.front();
            q.pop();
            
            int i = temp.first;
            int j = temp.second;
            
            for(int k = 0; k < 4; k++){
                int newi = i +x[k];
                int newj = j +y[k];
                
                if(newi >= 0 and newi < n and newj < m and newj >= 0 and c[newi][newj] != 'N' and ans[newi][newj] == -1){
                    ans[newi][newj] = ans[i][j]+ 1;
                    q.push({newi,newj});
                }  
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'N' or c[i][j] == '.') ans[i][j]=0;
                else if(ans[i][j] != -1) ans[i][j] *= 2;
            }
        }
        
        
        return ans;
        
    }
