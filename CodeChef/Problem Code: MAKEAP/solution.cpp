/*
Chef is given two integers AA and CC such that A \leq CA≤C.

Chef wants to find whether there exists any integer BB such that A, B,A,B, and CC are in arithmetic progression.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two space-separated integers AA and CC, the given integers.
Output Format
For each test case, output -1−1 if there exists no integer BB such that A, B,A,B, and CC are in arithmetic progression. Else, output the value of BB.
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int r = a + b;
	    if(r % 2 == 0){
	        cout<<r/2<<endl;
	    }else{
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}
