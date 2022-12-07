/*
Chef has made a list for his monthly expenses. The list has NN expenses with index 11 to NN. The money spent on each expense depends upon the monthly 
income of Chef.

Chef spends 50\%50% of his total income on the expense with index 11.
The money spent on the i^{th}i 
th
  expense (i>1)(i>1) is equal to 50\%50% of the amount remaining, after paying for all expenses with indices less than ii.
Given that Chef earns 2^X2 
X
  rupees in a month, find the amount he saves after paying for all NN expenses.
  */

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, x;
	    cin>>n>>x;
	    
	    x = pow(2,x);
	    for(int i = 1; i <= n; i++){
	        x = x/2;
	    }
	    cout<<x<<endl;;
	    
	}
	return 0;
}
