/*
A sorting algorithm AA is said to have more time complexity than a sorting algorithm BB 
if it uses more number of comparisons for sorting the same array than algorithm BB.

Given that algorithm AA uses XX comparisons to sort an array and algorithm 
BB uses YY comparisons to sort the same array, find whether algorithm AA has more time complexity.
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
		
		while( t-- > 0){
		    int x = sc.nextInt();
		    int y = sc.nextInt();
		    
		    System.out.println((x > y)? "YES" : "NO");
		}
	}
}
