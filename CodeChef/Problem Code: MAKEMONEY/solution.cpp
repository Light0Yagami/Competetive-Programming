/*
Chef has NN bags and an integer XX. The i^{th}i 
th
  bag contains A_iA 
i
​
  coins such that A_i \leq XA 
i
​
 ≤X.

In one operation, Chef can:

Pick any bag and increase its coins to XX. Formally, if he choses the i^{th}i 
th
  bag, he can set A_i = XA 
i
​
 =X.
Given that the cost of performing each operation is CC (C \leq X)(C≤X) coins and Chef can perform the above operation any (possibly zero) number of times, determine the maximum value of:

\sum_{i=1}^N A_i∑ 
i=1
N
​
 A 
i
​
  -− total cost paid by Chef, if Chef performs the operations optimally.
  */


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n, x,c;
	    cin>>n>>x>>c;
	    
	    int res = 0;
	    
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	        
	        if(x - arr[i] >= c){
	            res += x - c;
	        }else{
	            res += arr[i];
	        }
	   }
	   cout<<res<<endl;
	}
	return 0;
}
