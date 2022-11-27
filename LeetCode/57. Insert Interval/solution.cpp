/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        intervals.push_back({newInterval[0],newInterval[1]});
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
         for(int i = 0; i <= n  ;i++){
            int maxEnd = intervals[i][1];
            int j = i+1;
            
            while((j <= n) && (maxEnd >= intervals[j][0])){
                maxEnd = max(maxEnd,intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0],maxEnd});
            i = j -1;
        }
        return ans;
    }
};    
