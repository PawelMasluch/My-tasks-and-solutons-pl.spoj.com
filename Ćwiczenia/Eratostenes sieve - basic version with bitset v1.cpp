#include<cstdio>
#include<bitset>


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)


const int MAX_N = 1000000;


// isPrime[i] = 0 iff i is not prime
// isPrime[i] = 1 iff i is     prime
std::bitset <MAX_N+1> isPrime;


// Eratostenes sieve in O(n*loglog(n)) time.
// n >= 2
void EratostenesSieve(int n){
	REP(i,0,1,1){
		isPrime[i] = 0; // 0 and 1 are not primes
	}
	
	REP(i,2,n,1){
		isPrime[i] = 1; // initially, we assume that all numbers i=2,...,n are primes
	}
	
	FOR(i,2,n){
		if( isPrime[i] == 1 ){ // if i is prime
			REP(j,i*i,n,i){
				isPrime[j] = 0; // j is not prime because i | j and j > i >= 2
			}
		}
	}
}


int main(){
	
	int n;
	scanf( "%d", &n );
	
	EratostenesSieve(n);
	
	REP(i,0,std::min(n,50),1){
		
		if( isPrime[i] == 0 ){ // i is not prime
			printf( "i = %d is not prime\n", i);
		}
		else{ // i is prime
			printf( "i = %d is prime\n", i);
		}
	}
	
	return 0;
}
