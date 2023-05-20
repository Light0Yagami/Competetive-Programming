/*You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

*/

class Solution {
public:

    unordered_map<string,unordered_map<string,double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
        unordered_map<string,unordered_map<string,double>> gr;

        for(int i = 0; i < equations.size(); i++){
            double value = values[i];
            string dividend = equations[i][0];
            string divisor = equations[i][1];

            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1.0/value;
        }

        return gr;
    }

    void dfs(string node, string dest,unordered_map<string,unordered_map<string,double>> &gr, unordered_set<string>&vis, double& ans, double temp ){
        if(vis.find(node) != vis.end()) return;
        vis.insert(node);
        if(node == dest){
            ans = temp;
            return;
        }

        for(auto neighbour : gr[node]){
            dfs(neighbour.first,dest,gr,vis,ans,temp * neighbour.second);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> finalAns;
        unordered_map<string,unordered_map<string,double>> gr = buildGraph(equations,values);

        for(auto query : queries){
            string dividend = query[0];
            string divisor = query[1];

            if(gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()) finalAns.push_back(-1.0);
            else{
                unordered_set<string>vis;
                double ans = -1, temp = 1.0;
                dfs(dividend, divisor, gr, vis, ans , temp);
                finalAns.push_back(ans);
            }

        }
        return finalAns;
    }
};
