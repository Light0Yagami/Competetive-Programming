/*
Given an integer NN, help Chef in finding an NN-digit 
odd positive integer XX such that XX is divisible by 33 but not by 99.

\textbf{Note}:Note: There should not be any leading zeroes in XX. 
In other words, 003003 is not a valid 33-digit odd positive integer.
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
		    int n= sc.nextInt();
		    int arr[] = new int[n];
		    if(n==1) System.out.println(3);
		    else{
		        arr[0]=1;
		        for(int i=1;i<n;i++){
		           arr[i]=0; 
		        }
		        arr[n-1]=5;
		        for(int i=0;i<n;i++) System.out.print(arr[i]);
		        System.out.println();
		    }
		}
	}
}
