/*

Copyright (C) Pawel Masluch, 2021. All rights reserved.


Bibliography:
	1. https://eduinf.waw.pl/inf/alg/001_search/0012.php
	2. https://codeforces.com/blog/entry/54090
	3. https://cp-algorithms.com/algebra/prime-sieve-linear.html
	4. https://www.cs.utexas.edu/users/misra/scannedPdf.dir/linearSieve.pdf

*/

#include<cstdio>
#include<bitset>


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000000;


// isPrime[x] = 0 iff x is not prime
// isPrime[x] = 1 iff x is     prime
std::bitset<MAX_N+1> isPrime;


void linearSieve(int n){ // we find primes x, for x in {0,1,2,...,n} and  MAX_N >= n >= 2
	
	isPrime[0] = isPrime[1] = 0; // 0 and 1 are not primes
	REP(i,2,n){
		isPrime[i] = 1; // initially, all numbers >= 2 are primes
	}
	
	int p=2, q=2;
	
	while( p*q <= n ){
		
		LL P = p;
		int k=1;
		
		
		while( P*q <= n ){ // P*q = p^k * q <= n
			isPrime[ P*q ] = 0; // P*q = p^k * q is composite
			
			P *= p;
			++k;
		}
	
		
		// we find the smallest number, thought cuurently as prime, bigger than q
		do{
			++q;
		}
		while( isPrime[q] == 0 );
			
		
		if( p*q > n ){ // p*q > n
		
			// we find the smallest number, thought cuurently as prime, bigger than q
			do{
				++p;
			}
			while( isPrime[p] == 0 );
			
			q = p;
		}
	}
	
}


int main(){
	
	int n; // we find primes x, for x in {0,1,2,...,n} and  MAX_N >= n >= 2
	scanf( "%d", &n );
	
	linearSieve(n);
	
	REP(i,std::max(2,n-100),n){
		if( isPrime[i] == 0 ){
			printf( "isPrime[%d] = 0\n", i );
		}
		else{
			printf( "isPrime[%d] = 1\n", i );
		}
	}
	
	return 0;
}
