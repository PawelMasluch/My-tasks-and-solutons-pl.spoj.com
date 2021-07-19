/*

Copyright (C) Pawel Masluch, 2021. All rights reserved. 

Finding all primes in [1..2n+1] interval (n>=1) via Sundaram sieve.
Complexity:
	- time: O(n*log(n))
	- space: O(n)

*/


#include<bits/stdc++.h>


typedef std::vector <int> VI;
typedef std::vector <bool> VB;



#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define PB push_back


// We find all primes <= 2n+1 via Sundaram sieve.
//  10^7 >= n >= 1
VI Sundaram_sieve(int n){
	
	VB isPrime (n+1, true); // number 2i+1 (i=1,...,n) is initially prime (we consider only odd integers > 1)
	
	// ---------------------------
	
	int i=1, j;
	while( i*i <= n ){
		j = i;
		
		while( i + j + 2*i*j <= n ){
			isPrime[ i + j + 2*i*j ] = false;
			++j;
		}
		
		++i;
	}
	
	// ---------------------------
	
	VI res;		res.PB(2);
	REP(i,1,n){
		if( isPrime[i] == true ){
			res.PB( 2*i+1 );
		}
	}
	
	// ---------------------------
	
	isPrime.clear();
	
	// ---------------------------
	
	return res;
}


int main(){
	
	printf( "We'll find all primes in [1, 2n+1] interval (n>=1).\nEnter value of n: " );
	
	int n;
	scanf( "%d", &n );
	
	// ---------------------------
	
	VI primes = Sundaram_sieve(n);
	
	// ---------------------------
	
	for(auto it: primes){
		printf( "%d ", it );
	}
	printf( "\n" );
	
	// ---------------------------
	
	return 0;
}
