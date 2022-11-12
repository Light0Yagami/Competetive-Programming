/*
Chef will have NN guests in his house today. He wants to serve at least one dish to each of the NN guests. 
Chef can make two types of dishes. He needs one fruit and one vegetable to make the first type of dish and one 
vegetable and one fish to make the second type of dish. 
Now Chef has A fruits, B vegetables, and C fishes in his house. Can he prepare at least N dishes in total?
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
		
		//test case:
		int t = sc.nextInt();
		
		while(t-- > 0){
		    
		    int N = sc.nextInt();
		    int A = sc.nextInt();
		    int B = sc.nextInt();
		    int C = sc.nextInt();
		    
		    //count how many has build till now
		    //count = smaller from first two
		    int count = (B>A)?A:B;
		    
		    //remaining in B
		    B = Math.abs(B-A);
		    
		    //add the smaller one with count 
		    count += (B>C)?C:B;
		    
		    //output
		    System.out.println((count >= N)?"Yes": "NO");
		    
		    
		    
		    
		    
		}
		    
	}
}
