#include<cstdio>
#include<vector>


typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<PII, int> PIII;
typedef std::vector <PIII> VPIII;
typedef std::vector<int> VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
#define FOR(i,a,b) for(int i=a; i*i<=b; ++i)
#define prime first.first
#define exponent first.second
#define powerOfPrime second
#define MP std::make_pair


const int MAX_N = 1000000;


// smallestFactors[k] = ((p, alfa), p^alfa) (k=2,...,n) iff:
//		1. p^alfa | k and
//		2. !(p^(alfa+1) | k) and 
//		3. p is the smallest possible prime such that p | k
VPIII smallestFactors(MAX_N+1);


// sumOfDivisors[x] - sum of divisors of x (x=0,1,...,n).
// By definition: sumOfDivisors[0] = 0
VI sumOfDivisors(MAX_N+1);


// Eratostenes sieve in O(n*loglog(n)) time.
// n >= 2
// smallestFactors[0..1]  = ((0, 0), 1) which means that 0 and 1 are neither prime nor composite numbers 
void countSumOfDivisorsViaEratostenesSieve(int n){
	
	// Initialization
	REP(i,0,n,1){
		smallestFactors[i] = MP( MP(i, 1), i ); // initially, we assume that all numbers i=2,...,n are primes so i^1 | i for i=2,...,n
		sumOfDivisors[i] = 1;
	}
	
	smallestFactors[0] = smallestFactors[1] = MP( MP(0, 0), 1 ); // by definition
	
	
	// Eratostenes sieve
	FOR(i,2,n){
		if( smallestFactors[i].prime == i ){ // if i is prime
			REP(j,i*i,n,i){
				if( smallestFactors[j].prime == j ){ // if j hasn't been considered yet
					
					smallestFactors[j].prime = i;
					
					if( smallestFactors[ j / i ].prime == i ){
						smallestFactors[j].exponent = smallestFactors[ j / i ].exponent + 1;
						smallestFactors[j].powerOfPrime = smallestFactors[ j / i ].powerOfPrime * i;
					}
					else{
						smallestFactors[j].exponent = 1;
						smallestFactors[j].powerOfPrime = i;
					}
				}
			}
		} // after this loop: i is prime (i=2,...,n) iff smallestFactors[i] = ( (i,1), i )
	}
	
	// Sum of divisors via dynamic programming
	REP(i,2,n,1){
		sumOfDivisors[i] = sumOfDivisors[ i / smallestFactors[i].powerOfPrime ]   *   (   ( (LL)smallestFactors[i].powerOfPrime * smallestFactors[i].prime - 1 ) / ( smallestFactors[i].prime - 1 )   );
	}
}


int main(){
	
	int n;
	scanf( "%d", &n );
	
	countSumOfDivisorsViaEratostenesSieve(n);
	
	REP(i,1,std::min(n,100),1){
		printf( "sumOfDivisors[%d] = %d\n", i, sumOfDivisors[i] );
	}
	
	return 0;
}
