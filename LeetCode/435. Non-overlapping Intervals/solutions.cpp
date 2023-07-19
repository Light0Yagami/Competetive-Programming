/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to 
remove to make the rest of the intervals non-overlapping.
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;

        sort(intervals.begin(), intervals.end());

        int prev = 0;
        int curr = 1;

        while(curr != intervals.size()){
            if(intervals[prev][1] > intervals[curr][0]){
                if(intervals[prev][1] > intervals[curr][1]){
                    prev = curr;
                    curr++;
                    ans++;
                }else{
                    curr++;
                    ans++;
                }

            }else{
                prev = curr;
                curr++;
            }
        }




        return ans;

    }

};
