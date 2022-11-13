/*
Alice and Bob are playing a game. They have a common string S of length N. 
The players also have their individual strings A0 (belonging to Alice) and 
B (belonging to Bob) which are empty in the beginning. Game begins with Alice and both players take alternate turns.

In her/his turn, the player picks a single character from string S, 
adds it to the end of their individual string and deletes the picked character from string S.

The game continues until string S is empty. Find whether there exists a sequence of moves 
such that the strings A and B are same at the end of the game.
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
		
		while(t-- > 0){
		    int n = sc.nextInt();
		    String s = sc.next();
		    
		    if(check(s,n)){
		        System.out.println("YES");
		    }else{
		        System.out.println("NO");
		    }
	    }
		
	}
	
	public static boolean check(String s, int n){
	        int[] freq = new int[26];
 
            // counting frequency of all characters
            for (int i = 0; i < s.length(); i++)
            {
                freq[(s.charAt(i)) - 97] += 1;
            }
 
            // checking if any odd frequency
            // is there or not
            for (int i = 0; i < freq.length; i++)
            {
                if (freq[i] % 2 == 1)
                {
                    return false;
                }
            }
            return true;
	}
}
