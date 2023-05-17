/*

There is a rectangular path for a Train to travel consisting of n rows and m columns. The train will start from one of the grid's cells and it will be given a command in the form of string s consisting of characters L, R, D, U. Find if it is possible to travel the train inside the grid only.
Note:
If the train is at position (i,j)
on taking 'L' it goes to (i,j-1),
on taking 'R' it goes to (i,j+1),
on taking 'D' it goes to (i-1,j),
on taking 'U' it goes to (i+1,j).

*/

int side=0,niche=0,maxSide=0,minSide=0,maxNiche=0,minNiche=0;
        for(auto x:s){
            if(x=='R')side++;
            else if(x=='L')side--;
            else if(x=='U')niche--;
            else niche++;
            maxSide=max(maxSide,side);
            minSide=min(minSide,side);
            maxNiche=max(maxNiche,niche);
            minNiche=min(minNiche,niche);
        }
        if(maxSide+abs(minSide)+1>m)return 0;
        if(maxNiche+abs(minNiche)+1>n)return 0;
        return 1;
