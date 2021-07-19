/*

Copyright (C) Pawel Masluch, 2021. All rights reserved.

Finding Newton symbols (modulo M) using recursive formula, Pascal triangle and dynamic programming.

Bibliography:
	1. https://pl.wikipedia.org/wiki/Symbol_Newtona
	2. https://en.wikipedia.org/wiki/Binomial_coefficient

*/

#include<bits/stdc++.h>


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR(i,a,b,jump) for(int i=a; i<=b; i+=jump)


const int MAX_N = 1000;


LL N_choose_K[MAX_N+1][MAX_N+1];

LL M; // modulo; 4.5*10^18 >= M >= 1


// Finding Newton symbols (modulo M) using recursive formula, Pascal triangle and dynamic programming.
// for n,k >=0 and k <= n: 
//		(n choose k) = (n-1 choose k-1) + (n-1 choose k) (for 0<k<n) 
//	 or (n choose k) = 1 (for k=0 or k=n) 
void find_Newton_symbols_modulo(){
	
	LL one_mod_M = ( (M == 1) ? 0 : 1 );
	
	REP(n,0,MAX_N){
		N_choose_K[n][0] = one_mod_M;
		
		REP(k,1,n-1){
			N_choose_K[n][k] = ( N_choose_K[n-1][k-1] + N_choose_K[n-1][k] ) % M;
		}
		
		N_choose_K[n][n] = one_mod_M;
	}
}


int main(){
	
	printf( "Enter a value of modulo:\nM = " );
	scanf( "%lld", &M );
	
	// ------------------------
	
	find_Newton_symbols_modulo();
	
	// ------------------------
	
	printf( "\nResults:\n" );
	REP(n,0,10){
		REP(k,0,n){
			printf( "(%lld choose %lld) mod %lld = %lld\n", n, k, M, N_choose_K[n][k] );
		}
		
		printf( "\n" );
	}
	
	// ------------------------
	
	return 0;
}
