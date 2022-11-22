/*
Chef likes to mix colors a lot. Recently, she was gifted N colors A1, A2, ..., AN by her friend.

Chef wants to make the values of all her colors pairwise distinct, as they will then look stunningly beautiful. In order to achieve that, she can perform the following mixing operation zero or more times:

Choose any two colors. Let's denote their values by x and y.
Mix the color with value x into the color with value y. After the mixing, the value of the first color remains x, but the value of the second color changes to x + y.
Find the minimum number of mixing operations Chef needs to perform to make her colors beautiful.
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
		    int n = sc.nextInt();
		    long a [] = new long[n];
		    
		    HashMap<Long,Integer> map = new HashMap<>();
		    
		    for (int i = 0 ; i < n ; i++ ) {
		        a[i] = sc.nextLong();
		        map.put( a[i] , map.getOrDefault( a[i] , 0 ) + 1 );
		    }
		    
		    long ans = 0;
		    
		    for( long key : map.keySet() ){
		        ans += map.get(key) - 1;
		    }
		    
		    System.out.println(ans);
		}
	}
}
