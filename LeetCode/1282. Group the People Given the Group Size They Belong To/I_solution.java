/*
here are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.

You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, 
if groupSizes[1] = 3, then person 1 must be in a group of size 3.

Return a list of groups such that each person i is in a group of size groupSizes[i].

Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, 
return any of them. It is guaranteed that there will be at least one valid solution for the given input.
*/

class Solution {
    public static List<List<Integer>> groupThePeople(int[] groupSizes) {        
        int n = groupSizes.length;
        int i = 0,j=0;
        List<List<Integer>> ans = new ArrayList<>();
        
        for(i = 1; i <= n; i++){
            List<Integer> subans =  new ArrayList<>();

            for(j = 0; j< n; j++){
                if(groupSizes[j] == i){
                    if(subans.size() >= i){
                        ans.add(subans);
                        subans.clear();
                    }
                    subans.add(j);
                }
            }
            if(subans.size() > 0){
                ans.add(subans);
            }
        }
        return ans;
    }
}

// Time complexity = O(n)

// to decrease this we can change the first loop to run till the max element of array
    
class Solution {
    public static List<List<Integer>> groupThePeople(int[] groupSizes) {        
        int n = Arrays.stream(groupSizes).max().getAsInt();
        int m = groupSizes.length;
        int i = 0,j=0;
        List<List<Integer>> ans = new ArrayList<>();
        
        for(i = 1; i <= n; i++){
            List<Integer> subans =  new ArrayList<>();

            for(j = 0; j< m; j++){
                if(groupSizes[j] == i){
                    if(subans.size() >= i){
                        ans.add(subans);
                        subans.clear();
                    }
                    subans.add(j);
                }
            }
            if(subans.size() > 0){
                ans.add(subans);
            }
        }
        return ans;
    }
}
