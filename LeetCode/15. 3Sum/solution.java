/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

/*                                        SOLUTION APPROCH
                                          
                                            a + b + c = 0
                                            b + c = 0 - a

                                            b = low;
                                            c = high;

                                            if( high + low > -a) high--;
                                            if(high + low < -a) low++;

                                            to avoid repetion use nums[a] != nums[a-1] same for low and high pointer
*/
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
         List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        for(int i=0; i < n - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i+1, hi = n-1, sum = 0 - nums[i];

                while(low < hi){
                    if(nums[low] + nums[hi] == sum){

                        res.add(Arrays.asList(nums[i],nums[low],nums[hi]));

                        while(low < hi && nums[low] == nums[low+1]) low++;
                        while(low < hi && nums[hi] == nums[hi-1]) hi--;
                        low++; hi--;
                    }
                    else if(nums[low] + nums[hi] < sum){
                        low++;
                    }else{
                        hi--;
                    }
                }
            }

        }
        return res;


    }
}
