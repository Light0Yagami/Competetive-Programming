/*
Tracy gives Charlie a Directed Acyclic Graph with NN vertices. Among these NN vertices, KK vertices are sources, and LL vertices are sinks.

Find out the maximum number of edges this graph can have.

Note:

A source is a vertex with no incoming edge.
A sink is a vertex with no outgoing edge.
A vertex can be both, a source, and a sink.
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
		
		while(t-- >0){
		    long n = sc.nextLong();
		    long source = sc.nextLong();
		    long sink = sc.nextLong();
		    
		    long ans = 0l;
		    if(source + sink <= n){
		        ans = n * (n - 1) /2;
		        ans -= ((source * (source - 1))/2 + (sink * (sink -1)/2));
		    }
		    else{
		        long x  = source + sink - n;
		        n-=x;
		        source -= x;
		        sink -= x;
		        
		        ans += n * (n-1)/2;
		        ans -= (((source * (source - 1))/2) + ((sink * (sink -1))/2));
		    }
		    System.out.println(ans);
		}
	}
}
