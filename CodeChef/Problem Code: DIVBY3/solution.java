/*
You are given a binary string SS.
In one operation, you can pick an index and swap the characters S(i) and S(i+1) 

Find the minimum number of operations required, such that, the decimal representation 
of the final binary string is divisible by 33. If it is impossible to do so, print -1−1 instead.
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
		    int a = sc.nextInt(); // initial temp
		    int b = sc.nextInt(); // required temp
		    int x = sc.nextInt(); // hot water
		    int y = sc.nextInt(); // cold water
		    
		    if(a <= b){
		        System.out.println((b <= (a + x))?"YES":"NO");
		    }else{
		        System.out.println((b >= (a - y))?"YES":"NO");
		    }
		}
	}
}
