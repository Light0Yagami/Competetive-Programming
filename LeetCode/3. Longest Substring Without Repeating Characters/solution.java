/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
         int i = 0; 
        int j = 0;
        int n = s.length();
        int max = 0;
        Map<Character,Integer> map = new HashMap<>();
        char[] str = s.toCharArray();
        while(j <n){
            map.put(str[j],map.getOrDefault(str[j], 0)+1);
            if(map.{
                map.put(str[j],1);
                i++;
            }else{
                max = Math.max(max,(j-i+1));
                j++;
            }    
        }
        return max;
    }
}
