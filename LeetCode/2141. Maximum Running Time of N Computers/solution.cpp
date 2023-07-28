/*
You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.
  */

class Solution {
public:
    bool isPossible(vector<int>& batteries, long long time, int computers){
        long long totTime = 0;

        for(long long bTime : batteries){
            if(bTime < time) totTime += bTime;
            else totTime += time;
        }

        return (totTime >= time*computers);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        int sz = batteries.size();


        high = 1e14 ; // or we take high as the sum of of battteries
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;

            if(isPossible(batteries,mid,n)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        } 

        return ans;
    }
};
