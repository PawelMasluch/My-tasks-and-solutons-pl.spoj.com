/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Number of permutations with k inversions (slower version).
	
	Bibliography:
		1. https://www.geeksforgeeks.org/number-of-permutation-with-k-inversions/

*/

#include<bits/stdc++.h>



typedef long long LL;



#define REP(i,a,b) for(LL i=a; i<=b; ++i)





// Number of permutations of {1..N} set with exactly K inversions, modulo M.

// N, K, M - non-negative integers
// 4.5*10^18 >= M >= 1

// Complexity:
// 		Time: O(N*N*K)
//		Space: O(N*K)
LL exactly_k_inversions_slower_version(LL N, LL K, LL M){
	
	LL DP[N+1][K+1]; // DP[n][k] - number of permutations of {1..n} set with exactly k inversions
	REP(n,0,N){
		REP(k,0,K){
			DP[n][k] = 0;
		}
	}
	
	// -------------------------------
	
	LL one_mod_M = (  ( M == 1 ) ? 0 : 1  );
	
	// -------------------------------
	
	// Base cases.
	
	REP(n,0,N){
		DP[n][0] = one_mod_M; // only increasingly sorted permutation (so 1 permutation) has 0 inversions
	}
	
	REP(k,1,K){
		DP[0][k] = 0; // ther is no empty permutation with k>0 inversions 
	}
	
	// -------------------------------
	
	// Dynamic programming.
	
	REP(n,1,N){
		REP(k,1,K){
			REP(i,0,std::min(k,n-1)){
				DP[n][k] = (DP[n][k] + DP[n-1][k-i]) % M;
			}
		}
	}
	
	// -------------------------------
	
	/*
	REP(n,0,N){
		REP(k,0,K){
			printf( "DP[%lld][%lld] = %lld\n", n, k, DP[n][k] );
		}
		printf( "\n" );
	}
	*/
	
	// -------------------------------
	
	return DP[N][K];
}



int main(){
	
	LL N, K, M;
	
	printf( "We want to find a number of permutations of {1..N} set with exactly K inversions, modulo M.\n\nEnter a length of permutation:\nN = " );
	scanf( "%lld", &N );
	
	printf( "\nEnter a number of inversions:\nK = " );
	scanf( "%lld", &K );
	
	printf( "\nEnter a value of modulo (1 <= M <= 4.5*10^18):\nM = " );
	scanf( "%lld", &M );
	
	// -------------------------------
	
	printf( "\nNumber of permutations with K = %lld inversions: %lld\n", K, exactly_k_inversions_slower_version(N, K, M) );
	
	// -------------------------------
	
	return 0;
}

