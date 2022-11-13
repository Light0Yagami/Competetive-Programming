/*Let f be a function, such that, for an array A of size M, f(A) is defined as
...........
You are given an array CC of size NN. In one operation on the array, you can:

Choose an index ii (1\le i \le |C|)(1≤i≤∣C∣)
Select two positive integers XX and YY such that X+Y = C_i
Remove the element C_i from the array CC
Insert the elements XX and YY to the array CC
Find the maximum value of f(C)f(C) that can be obtained using any (possibly zero) number of given operations. 
Since this value can be huge, output the answer modulo 998244353998244353.
*/

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static final int mod = 998244353;
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		while(t-- > 0){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
        	long sum = 0;
        	for(int i = 0; i < n; i++){
        		  arr[i] = sc.nextInt();
        		  sum = (sum+ arr[i]) % mod;
        	}
		    
		    
		    System.out.println((sum * (sum -1)) % mod);
		}
	}
}
