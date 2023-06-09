/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0;
        int high = n-1;
        int mid;
        int pos = -1;

        while(low <= high){
            mid =low + (high - low)/2;
            
            if(letters[mid] > target){
                pos = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        if(pos == -1) return letters[0];

        return letters[pos];

    }
};
