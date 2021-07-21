/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Number of permutations with =/</>/<=/>=/!= k inversions.
	
	Bibliography:
		1. https://www.geeksforgeeks.org/number-of-permutation-with-k-inversions/

*/

#include<bits/stdc++.h>



typedef long long LL;



#define REP(i,a,b) for(LL i=a; i<=b; ++i)




// a*b (mod m).
// Assumption 1: a,b,m - integers
// Assumption 2: m != 0
LL multiply_modulo(LL a, LL b, LL m){
	
	a %= m;
	b %= m;
	
	LL res = 0;
	
	while ( b > 0 ){
		if( b % 2 == 1 ){
			res = (res+a) % m;
		}
		
		a = (a+a) % m;
		
		b /= 2;
	}
	
	return res;
}



// N! (mod M).
// 10^7 >= N >= 0
// 4.5*10^18 >= M >= 1
// Complexity:
//		 Time: O(N)
//		Space: O(1)
LL factorial_modulo(LL N, LL M){
	LL res = 1 % M;
	
	REP(i,1,N){
		res = multiply_modulo(res, i, M); 
	}
	
	return res;
}



// Number of permutations of {1..N} set with =/!=/<=/</>=/> K inversions., modulo M.

// N, K, M - non-negative integers
// 0 <= N <= 10^6
// 0 <= K <= 10^6
// N*K <= 10^8
// 4.5*10^18 >= M >= 1

// Complexity:
// 		Time: O(N*K)
//		Space: O(K)
void number_of_permutations_and_k_inversions(LL N, LL K, LL M, LL& equal, LL& not_equal, LL& less_or_equal, LL& less, LL& bigger_or_equal, LL& bigger){
	
	if ( M == 1 ){
		equal = not_equal = less_or_equal = less = bigger_or_equal = bigger = 0;
		return;
	} // from now: M >= 2
	
	/*
	// not absolutely necessary 
	if( N == 0 ){
		
		if( K == 0 ){
			equal = 1;
			not_equal = 0;
			less_or_equal = 1;
			less = 0;
			bigger_or_equal = 1; 
			bigger = 0;
		}
		else{ // K > 0
			equal = 0;
			not_equal = 1;
			less_or_equal = 1;
			less = 1;
			bigger_or_equal = 0; 
			bigger = 0;
		}
		
		return;
	} // from now: N >= 1
	*/
	
	// -------------------------------
	
	LL DP[2][K+1]; // DP[n%2][k] - number of permutations of {1..n} set with <= k inversions
	
	// -------------------------------
	
	// Initialization.
	
	REP(k,0,K){
		DP[0%2][k] = 1;
	}
	
	DP[1][0] = 1; // only increasingly sorted permutation (so 1 permutation) has 0 inversions
	
	/*
	REP(k,0,K){
		printf( "DP[%lld][%lld] = %lld\n", 0, k, DP[0][k] );
	}
	printf( "\n" );
	*/
	
	// -------------------------------
	
	// Dynamic programming.
	
	LL val;
	REP(n,1,N){
		
		REP(k,1,K){
			LL val = (   (k >= n)  ?  DP[(n-1) % 2][k - n]  :  0   );
			
			DP[ n%2 ][k] = (   DP[ (n-1)%2 ][k]  -  val  +  M   ) % M; // number of permutations of {1..n} set with exactly k inversions
			DP[ n%2 ][k] = ( DP[ n%2 ][k] + DP[ n%2 ][k-1] ) % M; // number of permutations of {1..n} set with exactly <= inversions
		}
		
		
		/*
		REP(k,0,K){
			printf( "DP[%lld][%lld] = %lld\n", n, k, DP[n%2][k] );
		}
		printf( "\n" );
		*/
		
	}
	
	// -------------------------------
	
	LL N_factorial = factorial_modulo( N, M ); // number of all permutations of {1..N} set
	
	// -------------------------------
	
	val = (   ( K > 0 )  ?  DP[N%2][K-1]  :  0   );
	
	equal = (  DP[N%2][K]  -  val  +  M  ) % M;
	not_equal = ( N_factorial - equal + M ) % M;
	less_or_equal = DP[N%2][K];
	less = ( less_or_equal - equal + M ) % M;
	bigger_or_equal = ( N_factorial - less + M ) % M; 
	bigger = ( bigger_or_equal - equal + M ) % M;
}



int main(){
	
	LL N, K, M;
	
	// -------------------------------
	
	printf( "We want to find a number of permutations of {1..N} set with = / != / <= / < / >= / > K inversions, modulo M.\n\nEnter a length of permutation:\nN = " );
	scanf( "%lld", &N );
	
	printf( "\nEnter a number of inversions:\nK = " );
	scanf( "%lld", &K );
	
	printf( "\nEnter a value of modulo (1 <= M <= 4.5*10^18):\nM = " );
	scanf( "%lld", &M );
	
	// -------------------------------
	
	LL equal, not_equal, less_or_equal, less, bigger_or_equal, bigger;
	
	// -------------------------------
	
	number_of_permutations_and_k_inversions(N, K, M, equal, not_equal, less_or_equal, less, bigger_or_equal, bigger);
	
	// -------------------------------
	
	printf( "\n\nResults:\n\nNumber of permutations with K = %lld inversions: %lld\n", K, equal );
	
	printf( "\nNumber of permutations with K != %lld inversions: %lld\n", K, not_equal );
	
	printf( "\nNumber of permutations with K <= %lld inversions: %lld\n", K, less_or_equal );
	
	printf( "\nNumber of permutations with K < %lld inversions: %lld\n", K, less );
	
	printf( "\nNumber of permutations with K >= %lld inversions: %lld\n", K, bigger_or_equal );
	
	printf( "\nNumber of permutations with K > %lld inversions: %lld\n", K, bigger );
	
	// -------------------------------
	
	return 0;
}

