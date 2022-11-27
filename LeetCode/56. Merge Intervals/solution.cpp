/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end());
        
        
        for(int i = 0; i < n ;i++){
            int maxEnd = intervals[i][1];
            int j = i+1;
            
            while((j < n) && (maxEnd >= intervals[j][0])){
                maxEnd = max(maxEnd,intervals[j][1]);
                j++;
            }
            sol.push_back({intervals[i][0],maxEnd});
            i = j -1;
        }
        
        
        return sol;
    }
};
 
