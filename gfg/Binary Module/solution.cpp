/*
You are given a binary string s and an integer m. You need to return an integer r. Where r = k%m, k is the binary equivalent of string s.
*/

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int ans = 0, temp = 1;
            for(int i = s.length()-1; i>=0 ; i--){
                if(s[i] == '1'){
                    ans += temp;
                    ans %= m;
                }
                temp *= 2;
                temp %= m;
            }
            return ans;
        }
};
