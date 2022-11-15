/*
You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. 
Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

Return an array answer, where answer[j] is the answer to the jth query.
*/

class Solution {
    public int[] countPoints(int[][] a, int[][] q) {
        int n = q.length;
        int[] ans = new int[n];
        
        int i,j, m = a.length;
        
        for(i = 0; i  < n; i++){
            for(j = 0; j < m; j++){
                int x = (int)Math.pow((q[i][0] - a[j][0]),2);
                int y = (int)Math.pow((q[i][1] - a[j][1]),2);
                if( x + y <= q[i][2] * q[i][2]) ans[i]++;
            }
        }
        
        
        
        return ans;
    }
}

