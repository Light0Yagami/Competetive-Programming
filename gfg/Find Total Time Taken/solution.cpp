/*You are given an array arr of size n, containing the values in between 1 to n & time of size n, containing time in sec, you are asked to determine the total time taken in order to pick all the array elements from left to right but there is a condition, If from left, previous elements are different it takes 1 Sec to pick & if element got repeated then it will take time[arr[i]].

NOTE:
1. It takes 1 sec to move from index i to i+1 (1 <= i < n).
2. 1-based indexing.

*/
int totalTime(int n, vector<int> &arr, vector<int> &time) {
         int res=0;
        int i=1;
        sort(arr.begin(),arr.end());
        while(i<n){
            if(arr[i-1]==arr[i]) res+=time[arr[i]-1];
            else res+=1;
            i++;
        }
        return res;
    }
