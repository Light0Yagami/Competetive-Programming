/*
Given n ranges of the form [p, q] which denotes all the numbers in the range [p, p + 1, p + 2,...q].  Given another integer q denoting the number of queries. The task is to return the kth smallest element for each query (assume k>1) after combining all the ranges.
In case the kth smallest element doesn't exist return -1. 
*/

vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(),range.end());
        vector<int> ans;
        for(int i=0;i<q;i++){
            int temp = queries[i];
            int last=-1,j=0,t;
            for(j=0;j<n;j++){
                if(last<range[j][1] and last>=range[j][0]){
                    t = range[j][1]-last;
                    if(t>=temp){
                        ans.push_back(last+temp);
                        break;
                    }
                    last=range[j][1];
                    temp-=t;
                }
                else if(last<range[j][1]){
                    t = range[j][1]-range[j][0]+1;
                    if(t>=temp){
                        ans.push_back(range[j][0]+temp-1);
                        break;
                    }
                    last=range[j][1];
                    temp-=t;
                }
            }
            if(j==n)ans.push_back(-1);
        }
        return ans;
    }
