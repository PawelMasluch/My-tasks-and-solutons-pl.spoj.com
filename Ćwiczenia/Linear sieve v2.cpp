/*

Copyright (C) Pawel Masluch, 2021. All rights reserved.


Bibliography:
	1. https://eduinf.waw.pl/inf/alg/001_search/0012.php
	2. https://codeforces.com/blog/entry/54090
	3. https://cp-algorithms.com/algebra/prime-sieve-linear.html
	4. https://www.cs.utexas.edu/users/misra/scannedPdf.dir/linearSieve.pdf

*/

#include<cstdio>
#include<vector>


typedef long long LL;
typedef std::pair <int, int> PII;
typedef std::pair <PII, int> PIII;
typedef std::vector <PIII> VPIII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define MP std::make_pair
#define prime first.first
#define exponent first.second
#define powerOfPrime second



const int MAX_N = 100000000;


/*
	smallestPrimeFactors[x] = (p, alfa, p^alfa) iff:
		1. p^alfa | x
		2. ![ p^(alfa+1) | x ]
		3. p is smallest prime such that p|x
*/
VPIII smallestPrimeFactors(MAX_N+1);


void linearSieve(int n){ // we find smallest prime factors, for x in {0,1,2,...,n} and  MAX_N >= n >= 2
	
	REP(i,0,1){
		smallestPrimeFactors[i] = MP( MP(0, 0), 1 ); // by definition	
	}
	
	REP(i,2,n){
		smallestPrimeFactors[i] = MP( MP(i, 1), i ); // initially, we assume that all numbers i in {2,...,n} are primes so smallestPrimeFactors[i] = (i, 1, i^1=i) 
	}
	
	int p=2, q=2;
	
	while( p*q <= n ){
		
		LL P = p;
		int k = 1;
		
		
		while( P*q <= n ){ // P*q = p^k * q <= n
			
			// P*q = p^k * q is composite
			smallestPrimeFactors[ P*q ].prime = p;
			smallestPrimeFactors[ P*q ].exponent = k;
			smallestPrimeFactors[ P*q ].powerOfPrime = P; // p^k
			if( q == p ){
				++smallestPrimeFactors[ P*q ].exponent; // k+1
				smallestPrimeFactors[ P*q ].powerOfPrime *= p; // p^(k+1)
			}
			
			P *= p;
			++k;
		}
	
		
		// we find the smallest number, thought cuurently as prime, bigger than q
		do{
			++q;
		}
		while( smallestPrimeFactors[q].prime < q );
			
		
		if( p*q > n ){ // p*q > n
		
			// we find the smallest number, thought cuurently as prime, bigger than q
			do{
				++p;
			}
			while( smallestPrimeFactors[p].prime < p );
			
			q = p;
		}
	}
	
}


int main(){
	
	int n; // we find smallest prime factors, for x in {0,1,2,...,n} and  MAX_N >= n >= 2
	scanf( "%d", &n );
	
	linearSieve(n);
	
	REP(i,std::max(2,n-100),n){
		printf( "smallestPrimeFactors[%d] = (%d, %d, %d)\n", i, smallestPrimeFactors[i].prime, smallestPrimeFactors[i].exponent, smallestPrimeFactors[i].powerOfPrime );
	}
	
	return 0;
}
