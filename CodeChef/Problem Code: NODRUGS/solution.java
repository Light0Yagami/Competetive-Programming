/*There are NN people participating in a race. The N^{th}N 
th
  participant is your friend, so you want him to win. You are not a man of ethics, so you decided to inject some units of a Performance Enhancement Drug (don't ask where that came from) in your friend's body.

From the charts, you came to know the speed of every player. Formally, for a player ii, his speed is denoted by S_i
The change in speed with one unit of the drug is KK units. Note that KK can be negative, which means the drug has more side effects than benefits.
Of course, there will be a drug test before the race, so your friend will be caught if the number of units of the drug in his blood is greater than or equal to LL.
You need to determine whether you can help your friend to win the race (with or without drugs), without getting caught.

Note: A player wins the race if he has the maximum speed among all the participants. If there are more than one people with a maximal speed, they tie at first place, and no one wins!
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
			int n = sc.nextInt();
			int k = sc.nextInt();
			int l = sc.nextInt();

			int[] arr = new int[n];
			for(int i = 0; i < n ;i++){
				arr[i] = sc.nextInt();
			}

			int in_speed = arr[n-1];
			Arrays.sort(arr);
			if(k > 0){
				if(arr[n-1] < in_speed + k * (l-1)) System.out.println("Yes");
				else System.out.println("No");

			}else{
			    if(in_speed < arr[n-1])
				System.out.println("No");
				else
				System.out.println("yes");
			}
		}
	}
}
