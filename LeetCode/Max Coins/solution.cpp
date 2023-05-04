/*
You are given a 2D integer array ranges whose length is n where ranges[i]=[starti, end,coinsi] means all integers from starti to endi inclusive starti and endi are present and we get coinsi amount of coins when we select this ith range. You can select at most two intervals so as to collect maximum coins but if you select two ranges then those two ranges should not intersect or overlap but can touch each other.

Note: You can select at max 2 ranges and they should not intersect with each other but they can touch themselves.
*/

int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(),ranges.end());
        vector<int> Profit(n);
        int i;
        Profit[n-1] = ranges[n-1][2];
        for(i = n - 2; i >= 0; i--){
            Profit[i] = max(Profit[i+1], ranges[i][2]);
        }
        
        int ans = INT_MIN;
        for(i = 0; i < n; i++){
            int sum = ranges[i][2];
            int low = i+1, high = n-1,mid,profit = 0;
            
            while(low <= high){
                mid = (high + low)/2;
                if(ranges[mid][0] >= ranges[i][1]){
                    high = mid - 1;
                    profit = Profit[mid];
                }else{
                    low = mid + 1;
                }
            }
            
            sum += profit;
            ans = max(ans,sum);
        }
        
        
        return ans;
    }
