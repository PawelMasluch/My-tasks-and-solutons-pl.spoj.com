#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b,step) for(int i=a; i<=b; i+=step)


int main(){
	
	int N; // 1 <= N <= 10^6
	scanf( "%d", &N );
	
	int isPrime[N+1];
	isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime
	
	REP(i,2,N,1){
		isPrime[i] = 1; // i is prime
	}
	
	// Eratostenes sieve
	for(int i=2; i*i<=N; ++i){ // for all i <= sqrt(N)
		if( isPrime[i] == 1 ){ // if i is prime
			REP(j,i*i,N,i){ // for all multiple of i >= i*i
				isPrime[j] = 0; // j is composite
			}
		}	
	}
	
	// Calculating a number of prime numbers <= N
	REP(i,3,N,1){
		isPrime[i] += isPrime[i-1];
	}
	
	// Printing a result: a number of prime numbers <= N
	printf( "%d\n", isPrime[N] );
	
	return 0; 
}
