/*
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
*/
class Solution {
public:
    double average(vector<int>& salary) {
        int n =salary.size();
        sort(salary.begin(), salary.end());
        int sum = 0;
        for(int i = 1; i < n -1; i++){
            sum += salary[i];
        }
        return (double)sum/(n-2);
    }
};
