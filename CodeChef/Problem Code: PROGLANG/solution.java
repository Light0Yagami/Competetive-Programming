/*
Chef is a software developer, so he has to switch between different languages sometimes. Each programming 
language has some features, which are represented by integers here.

Currently, Chef has to use a language with two given features AA and BB. He has two options --- switching to a language with 
two features A_1 and B_1, or to a language with two features A_2 and B_2 All four features of these two languages are pairwise distinct.

Tell Chef whether he can use the first language, the second language or neither of these 
languages (if no single language has all the required features).

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
		for(int i =0;i<t;i++)
		{
		    int a = sc.nextInt();
		    int b = sc.nextInt();
		      int w = sc.nextInt();
		        int x = sc.nextInt();
		          int y = sc.nextInt();
		            int z = sc.nextInt();
		            
		            if((a==w&&b==x)||(a==x&&b==w))
		            System.out.println(1);
		            else if((a==y&&b==z)||(a==z&&b==y))
		            System.out.println(2);
		            else
		            System.out.println(0);
		}
	}
}
