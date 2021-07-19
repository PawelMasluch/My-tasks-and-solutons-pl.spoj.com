#include<cstdio>
#include<vector>
#include<bitset>


typedef std::vector <int> VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)


const int MAX_NUMBER = 100000000; // maximum number to be checked for primeness 
const int HALF_MAX_NUMBER = MAX_NUMBER/2; // floor( MAX_NUMBER/2 )
const int MAX_N = 10000000; // maximum length of range of checked (for primeness) numbers 


// We want to find biggest prime factors in range [a,b].
int a, b;


// isSmallPrime[i] = 0 iff i is not prime
// isSmallPrime[i] = 1 iff i is     prime
std::bitset <HALF_MAX_NUMBER+1> isSmallPrime;


// // We find biggest prime factors for all numbers i in {a..b} (a<=b).
// biggestFactors[k] = p (k=2,...,n) iff:
//		1. p | k+a and
//		2. p is the biggest possible prime such that p | k+a
VI biggestFactors(MAX_N+1);


// Finding small primes via Eratostenes sieve.
void findSmallPrimes(int b){
	REP(i,0,1,1){
		isSmallPrime[i] = 0; // 0 and 1 are not primes
	}
	
	REP(i,2,b/2,1){
		isSmallPrime[i] = 1; // initially, we assume that all numbers i=2,...,SQRT_MAX_NUMBER are primes
	}
	
	FOR(i,2,b/2){
		if( isSmallPrime[i] == 1 ){ // if i is prime
			REP(j,i*i,b/2,i){
				isSmallPrime[j] = 0; // j is not prime because i | j and j > i >= 2
			}
		}
	}
}


// min k: k*B >= A
// 10^9 >= A,B > 0
int ceil(int A, int B){
	return (A + B - 1) / B;
}


// Eratostenes sieve in O(n*loglog(n)) time.
// 2 <= a <= b <= 10^8 = MAX_NUMBER
// |b-a| <= MAX_N
void EratostenesSieve(int a, int b){
	
	findSmallPrimes(b);
	
	REP(i,a,b,1){
		biggestFactors[i-a] = i; // initially, we assume that all numbers i=a,...,b are primes so i | i for i=a,...,b
	}
	
	REP(i,2,b/2,1){
		if( isSmallPrime[i] == 1 ){ // if i is prime
			REP(j,ceil(a,i)*i,b,i){ // ceil(a,i*i)*i*i - minimal number x such that i|x and x >= a
				biggestFactors[j-a] = i;
			}
		} // after this loop: i is prime (i=2,...,n) iff biggestFactors[i-a] = i
	}
}


int main(){
	
	int a, b;
	scanf( "%d %d", &a, &b );
	
	EratostenesSieve(a, b);
	
	REP(i,a,std::min(a+50,b),1){
		printf( "i = %d: biggest prime factor is %d\n", i, biggestFactors[i-a] );
	}
	
	return 0;
}
