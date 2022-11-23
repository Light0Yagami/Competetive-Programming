/*J has an array AA initially of length NN. He can perform the following operation on AA:

1) Pick any index ii (1 \le i \le |A|)(1≤i≤∣A∣) such that A_i \gt 1A i>1\\
2) Select any two integers XX and YY such that X + Y = A_iand X, Y \ge 1X,Y≥1\\
3) Replace A_i with XX and YY

Note that the length of the array increases by 11 after each operation.

For example, if A = [4, 6, 7, 2]A=[4,6,7,2], he can select i = 1i=1 and select X = 1, Y = 3X=1,Y=3 (since X + Y = A_1X+Y=A 1). 
After the operation array becomes: [\underline{4}, 6, 7, 2] \rightarrow [\underline{1}, \underline{3}, 6, 7, 2][ 4,6,7,2]→[ 1,3,6,7,2].

JJ wants to make AA palindromic. Find the minimum number of operations to do so.

It is guaranteed that AA can be converted to a palindromic array by using the above operation.

Note: An array is called a palindrome if it reads the same backwards and forwards, for e.g. [1, 3, 3, 1][1,3,3,1] and 
[6, 2, 6][6,2,6] are palindromic.
*/

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while(t-->0){
			int n = sc.nextInt();
			int[] arr = new int[n];
			
			for(int i = 0; i < n;i++){
				arr[i] = sc.nextInt();
			}

			int lo =0, hi = n-1,count = 0;
			while(lo < hi){
			    if(arr[lo] == arr[hi]){
				    lo++;
			    	hi--;
				}else if(arr[lo] < arr[hi]){
					arr[hi] = arr[hi] - arr[lo];
					lo++;
					count++;
				}else{
					arr[lo] = arr[lo]- arr[hi];
					hi--;
					count++;
				}
				
			}
			System.out.println(count);
		}
	}
}

