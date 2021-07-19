/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	For a given number x in {0,1,...,n}, we find a number of prime factors of x. 

*/

#include<cstdio>
#include<vector>


typedef std::pair <int, int> PII;
typedef std::pair <PII, int> PIII;
typedef std::vector <PIII> VPIII;
typedef std::vector <int> VI;


#define REP(i,a,b,jump) for(int i=a; i<=b; i+=jump)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)
#define prime first.first
#define exponent first.second
#define powerOfPrime second
#define MP std::make_pair


const int MAX_N = 1000000;


// smallestPrimeFactors[k] = (p, alfa, p^alfa) (k=2,...,n) iff:
//		1. p^alfa | k and
//		2. !(p^(alfa+1) | k) and 
//		3. p is the smallest possible prime such that p | k
VPIII smallestPrimeFactors(MAX_N+1);


// numberOfPrimeFactors[x] - number of prime factors of x
VI numberOfPrimeFactors(MAX_N+1);


// Eratostenes sieve in O(n*loglog(n)) time.
// n >= 2
void EratostenesSieve(int n){
	
	REP(i,0,1,1){ // 0 and 1 are neither prime nor composite numbers
		smallestPrimeFactors[i] = MP( MP(0, 0), 1 ); // by definition
		numberOfPrimeFactors[i] = 0; // by definition
	}
	
	REP(i,2,n,1){
		smallestPrimeFactors[i] = MP( MP(i, 1), i ); // initially, we assume that all numbers i=2,...,n are primes so smallestPrimeFactors[i] = (i, 1, i^1 = i) for i=2,...,n
		numberOfPrimeFactors[i] = 1; // initially, we assume that all numbers i=2,...,n are primes so numberOfPrimeFactors[i] = 1 for i=2,...,n
	}
	
	// -----------------
	
	FOR(i,2,n){
		if( smallestPrimeFactors[i].prime == i ){ // if i is prime
			REP(j,i*i,n,i){
				if( smallestPrimeFactors[j].prime == j ){ // if j hasn't been considered yet
					
					smallestPrimeFactors[j].prime = i;
					
					if( smallestPrimeFactors[ j / i ].prime == i ){
						smallestPrimeFactors[j].exponent = smallestPrimeFactors[ j / i ].exponent + 1;
						smallestPrimeFactors[j].powerOfPrime = smallestPrimeFactors[ j / i ].powerOfPrime * i;
					}
					else{
						smallestPrimeFactors[j].exponent = 1;
						smallestPrimeFactors[j].powerOfPrime = i;
					}
				}
			}
		}
	} // after this loop: i is prime (i=2,...,n) iff smallestPrimeFactors[i] = (i,1,i)
	
	// ------------------------
	
	// Finding numbers of prime factors using dynamic programming.
	REP(i,2,n,1){
		numberOfPrimeFactors[i] = numberOfPrimeFactors[ i / smallestPrimeFactors[i].powerOfPrime ] + 1;
	}
}


int main(){
	
	printf( "Data input\nEnter an upper bound of sieve n:\nn = " );
	
	int n;
	scanf( "%d", &n );
	
	// -----------------------
	
	EratostenesSieve(n);
	
	// -----------------------
	
	printf( "\n\nResults:\nSmallest prime factors:\n" );
	
	REP(i,2,std::min(n,100),1){
		printf( "i = %d: smallestPrimeFactors[%d] = (%d, %d, %d)\n", i, i, smallestPrimeFactors[i].prime, smallestPrimeFactors[i].exponent, smallestPrimeFactors[i].powerOfPrime ); 
	}	
	
	// -----------------------
	
	printf( "\n\nNumber of prime factors:\n" );
	
	REP(i,2,std::min(n,100),1){
		printf( "i = %d: number of prime factors is %d\n", i, numberOfPrimeFactors[i] );
	}
	
	// -----------------------
		
	return 0;
}
