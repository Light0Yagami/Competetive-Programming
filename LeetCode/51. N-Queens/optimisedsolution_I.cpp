  vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return{{"Q"}};
        
        string s(n,'.');
        vector<string> v(n,s);
        
        //col_wize fill ->optimize map
        vector<int> RowChk(n,0),
                    lorDiag((2*n)-1,0),
                    uprDiag((2*n)-1,0);

        fun(0,n,v,RowChk,lorDiag,uprDiag);
        return  ans;  
    }
    void fun(int col,int n,vector<string> &v,vector<int> &RowChk,vector<int>  &lorDiag,vector<int> &uprDiag){

    if(col==n) {
       ans.push_back(v); 
       return;
    }
    for(int r=0;r<n;r++) //upr -> n-1-r+col
       if(RowChk[r]==0 && lorDiag[r+col]==0 && uprDiag[n-1+col-r]==0)     
            {
                v[r][col]='Q';
                RowChk[r]=1;
                lorDiag[r+col]=1;
                uprDiag[n-1+col-r]=1; 
                //next pos
                fun(col+1,n,v,RowChk,lorDiag,uprDiag);
                //backtrack
                v[r][col]='.';
                RowChk[r]=0;
                lorDiag[r+col]=0;
                uprDiag[n-1+col-r]=0; 
            }
    }
