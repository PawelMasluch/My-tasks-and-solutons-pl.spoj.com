#include<cstdio>
#include<vector>


typedef std::pair<int, int> PII;
typedef std::vector <PII> VPII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)
#define prime first
#define exponent second
#define MP std::make_pair


const int MAX_N = 1000000;


// biggestFactors[k] = (p, alfa) (k=2,...,n) iff:
//		1. p^alfa | k and
//		2. !(p^(alfa+1) | k) and 
//		3. p is the biggest possible prime such that p | k
VPII biggestFactors(MAX_N+1);


// Eratostenes sieve in O(n*loglog(n)) time.
// n >= 2
// biggestFactors[0..1]  = (0, 0) which means that 0 and 1 are neither prime nor composite numbers 
void EratostenesSieve(int n){
	REP(i,0,1,1){
		biggestFactors[i] = MP(0, 0);
	}
	
	REP(i,2,n,1){
		biggestFactors[i] = MP(i, 1); // initially, we assume that all numbers i=2,...,n are primes so i^1 | i for i=2,...,n
	}
	
	REP(i,2,n/2,1){
		if( biggestFactors[i].prime == i ){ // if i is prime
			
			REP(j,2*i,n,i){
				
				biggestFactors[j].prime = i;
					
				if( biggestFactors[ j / i ].prime == i ){
					biggestFactors[j].exponent = biggestFactors[ j / i ].exponent + 1;
				}
				else{
					biggestFactors[j].exponent = 1;
				}
			}
		} // after this loop: i is prime (i=2,...,n) iff biggestFactors[i] = (i,1)
	}
}


int main(){
	
	int n;
	scanf( "%d", &n );
	
	EratostenesSieve(n);
	
	REP(i,2,std::min(n,50),1){
		printf( "i = %d: biggest prime factor and its maximal exponent is (%d, %d)\n", i, biggestFactors[i].prime, biggestFactors[i].exponent );
	}
	
	return 0;
}
