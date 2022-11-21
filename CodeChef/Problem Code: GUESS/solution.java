/*
Alice and Bob, both have to drink water. But they both don't want to go, so they will play a 
game to decide who will fetch water for both of them. Alice will choose a number randomly between 1 and N 
(both inclusive) and Bob will choose a number randomly between 1 and M (both inclusive). Both will write their numbers on a 
slip of paper. If sum of numbers choosen by both is odd, then Alice will go, else Bob will go.
What is probability that Alice will go?
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
		int cases = sc.nextInt();
		for (int i=0;i<cases;i++ ){
		    long a = sc.nextInt();
		    long b = sc.nextInt();
		    if(a==1 && b==1){
		        System.out.println("0/1");
		    }
		    else if(a%2!=0 && b%2!=0){
		        long x = (a*b)/2;
		        long y  = a*b;
		        System.out.println(x + "/" + y);
		    }
		    else{
		        System.out.println("1/2");
		    }
		    
		} 
	}
}
