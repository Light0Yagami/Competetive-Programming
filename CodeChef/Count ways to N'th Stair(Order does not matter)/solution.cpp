/*
There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
*/

/ recursive
int nthStair(int n){
	if(n == 0) return 1;
	if(n < 0) return 0;

	return nthStair(n-2) + 1;
}

// memoization
int nthStairHelper(int n, vector<int> &dp){
    if(n == 0) return 1;
    if(n < 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
    return dp[n] = nthStairHelper(n-2, dp) + 1;
}

int nthStair(int n){
    vector<int> dp(n+1, -1);
    return nthStairHelper(n, dp);
}

// tabulation
int nthStair(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-2] + 1; 
    }
    
    return dp[n];
}

// space opptimization
int nthStair(int n){
	int a = 1, b = 1, c = 0;

	for(int i=2;i<=n;i++) {
	    c = a + 1;
	    a = b;
	    b = c;
	}
	return b;
}
