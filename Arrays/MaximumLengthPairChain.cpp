 Maximum length pair chain
You are given ‘N’ pairs of integers in which the first 
number is always smaller than the second number i.e 
in pair (a,b) -> a < b always. Now we define a pair 
chain as the continuous arrangement of pairs in which 
a pair (c,d) can follow another pair (a,b) only when b < c.
Find the length of the longest pair chain that can be 
formed using the given pairs.

//code

// CPP program for above approach
#include <bits/stdc++.h>
using namespace std;

// Structure for a Pair 
class Pair 
{
	public:
	int a; 
	int b; 
}; 

// This function assumes that arr[] 
// is sorted in increasing order 
// according the first 
// (or smaller) values in Pairs. 
int maxChainLength( Pair arr[], int n) 
{ 
	int i, j, max = 0; 
	int *mcl = new int[sizeof( int ) * n ]; 
	
	/* Initialize MCL (max chain length)
	values for all indexes */
	for ( i = 0; i < n; i++ ) 
		mcl[i] = 1; 
	
	/* Compute optimized chain 
	length values in bottom up manner */
	for ( i = 1; i < n; i++ ) 
		for ( j = 0; j < i; j++ ) 
			if ( arr[i].a > arr[j].b && 
					mcl[i] < mcl[j] + 1) 
				mcl[i] = mcl[j] + 1; 
	
	// mcl[i] now stores the maximum 
	// chain length ending with Pair i 
	
	/* Pick maximum of all MCL values */
	for ( i = 0; i < n; i++ ) 
		if ( max < mcl[i] ) 
			max = mcl[i]; 
	
	/* Free memory to avoid memory leak */
	
	return max; 
} 
	

/* Driver code */
int main() 
{ 
	Pair arr[] = { {5, 24}, {15, 25}, 
						{27, 40}, {50, 60} }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Length of maximum size chain is "
				<< maxChainLength( arr, n ); 
	return 0; 
} 

