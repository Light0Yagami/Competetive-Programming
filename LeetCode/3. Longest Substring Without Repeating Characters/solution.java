/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        HashSet<Character> set = new HashSet<>();
        int i = 0,j = 0,n = s.length();
        while(j < n){
            if(set.contains(s.charAt(j))){
                i++;
                set.remove(s.charAt(j));
            }else{
                set.add(s.charAt(j));
                j++;
                max = Math.max(max,set.size());
                
            }
        }
        return max;
    }
}
