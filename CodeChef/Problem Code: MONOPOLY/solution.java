/*
Chef is the financial incharge of Chefland and one of his duties is identifying if any company has gained a 
monopolistic advantage in the market.

There are exactly 33 companies in the market each of whose revenues are denoted by R_1 R_2
and R_3 respectively. A company is said to have a monopolistic advantage if its revenue is strictly greater 
than the sum of the revenues of its competitors.

Given the revenue of the 33 companies, help Chef determine if any of them has a monopolistic advantage.
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
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while(t-->0){
			int r1 = sc.nextInt();
			int r2 = sc.nextInt();
			int r3 = sc.nextInt();

			if(r1 > r2 + r3 || r2 > r3 + r1 || r3 > r2 + r1){
				System.out.println("Yes");
			}else{
				System.out.println("No");
			}
			
		}
	}
}
