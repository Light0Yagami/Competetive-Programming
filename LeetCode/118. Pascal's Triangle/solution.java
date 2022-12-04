/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
       List<List<Integer>> result = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Integer> init = new ArrayList<>();
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    init.add(1);
                }else{
                   init.add(result.get(i-1).get(j-1)+result.get(i-1).get(j)); 
                }
            }
            result.add(init);
        }
        return result;
    }
        
}
