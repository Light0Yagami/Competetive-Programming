/*
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
*/

#define mod 1000000007
class Solution {
public:

/*
    int solve(int len, int zero, int one, vector<int> &dp){
        if(len == 0) return 1;
        if(len < 0) return 0;
        
        if(dp[len] != -1) return dp[len];

        long long sum = solve(len-one,zero,one,dp) + solve(len - zero,zero,one,dp);

        return sum;
    }

    int countGoodStrings(int low, int high, int zero,int one){
        int ans = 0;
        vector<int> dp(high+1, -1);
        for(int i = low; i <= high; i++){
            ans = ans + (solve(i, zero,one,dp) % mod);
        }
        return ans;
    }
*/

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        int ans = 0;
        for(int len = 1; len <= high; len++){
            if(len >= zero)
                dp[len] = dp[len-zero];
            if(len >= one)
                dp[len] = (dp[len] + dp[len - one])%mod;
            if(len >= low)
            ans = (ans + dp[len])%mod;
        }   
        return ans;
    }
};
