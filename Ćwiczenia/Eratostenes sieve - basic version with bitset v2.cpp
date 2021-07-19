#include<cstdio>
#include<bitset>


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)


const int MAX_NUMBER = 1000000000; // maximum number to be checked for primeness 
const int SQRT_MAX_NUMBER = 31622; // floor( sqrt(MAX_NUMBER) )
const int MAX_N = 10000000; // maximum length of range of checked (for primeness) numbers 



// We check primeness for all numbers i in {a..b} (a<=b).
// isPrime[i] = 0 iff i+a is not prime
// isPrime[i] = 1 iff i+a is     prime
std::bitset <MAX_N+1> isPrime;


// isSmallPrime[i] = 0 iff i is not prime
// isSmallPrime[i] = 1 iff i is     prime
std::bitset <SQRT_MAX_NUMBER+1> isSmallPrime;


// Finding small primes via Eratostenes sieve.
void findSmallPrimes(){
	REP(i,0,1,1){
		isSmallPrime[i] = 0; // 0 and 1 are not primes
	}
	
	REP(i,2,SQRT_MAX_NUMBER,1){
		isSmallPrime[i] = 1; // initially, we assume that all numbers i=2,...,SQRT_MAX_NUMBER are primes
	}
	
	FOR(i,2,SQRT_MAX_NUMBER){
		if( isSmallPrime[i] == 1 ){ // if i is prime
			REP(j,i*i,SQRT_MAX_NUMBER,i){
				isSmallPrime[j] = 0; // j is not prime because i | j and j > i >= 2
			}
		}
	}
}


// min k: k*b >= a
// a,b > 0
int ceil(int a, int b){
	return (a + b - 1) / b;
}


// Eratostenes sieve in O(n*loglog(n)) time.
// 2 <= a <= b <= 10^9 = MAX_NUMBER
// |b-a| <= MAX_N
void EratostenesSieve(int a, int b){
	
	findSmallPrimes();
	
	REP(i,a,b,1){
		isPrime[i-a] = 1; // initially, we assume that all numbers from {a, ..., b} set are primes
	}
	
	FOR(i,2,b){
		if( isSmallPrime[i] == 1 ){ // if i is prime
			REP(j,ceil(a,i*i)*i*i,b,i){ // ceil(a,i*i)*i*i - minimal number x such that i*i|x and x >= a
				isPrime[j-a] = 0; // j is not prime because i|j and j > i >= 2
			}
		}
	}
}


int main(){
	
	int a, b;
	scanf( "%d %d", &a, &b );
	
	EratostenesSieve(a, b);
	
	REP(i,a,std::min(a+50,b),1){
		
		if( isPrime[i-a] == 0 ){ // i is not prime
			printf( "i = %d is not prime\n", i);
		}
		else{ // i is prime
			printf( "i = %d is prime\n", i);
		}
	}
	
	return 0;
}
