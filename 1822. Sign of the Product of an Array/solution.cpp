/*
There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto i : nums){
            if(i == 0) return 0;
            else if(i < 0) ans *= -1;
            else ans *= 1;
        }

        return ans > 0 ? 1 : -1;

    }
};
