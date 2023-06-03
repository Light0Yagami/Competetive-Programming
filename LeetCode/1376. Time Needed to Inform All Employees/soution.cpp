/*
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.
*/

class Solution {
public:

    void dfs(int node,map<int,vector<int>>& adj, vector<int>& informTime, int count, int &ans){
        ans = max(ans,count);

        for(int &neighbour: adj[node]){
            dfs(neighbour,adj,informTime,count+informTime[node],ans);
        }

    }


    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int>> adj;
        for(int i = 0; i< n; i++){
            int parent = manager[i];
            int child = i;

            adj[parent].push_back(child);
        }

        int ans = INT_MIN;
        int count = 0;

        dfs(headID,adj,informTime,count,ans);


        return ans;
    }
};

