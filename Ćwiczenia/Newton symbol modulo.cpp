/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Finding a Newton symbol (n choose k) modulo m.

*/

#include<cstdio>
#include<vector>
#include<bitset>



typedef long long LL;
typedef std::vector <bool> VB;
typedef std::vector <int> VI;
typedef std::vector <LL> VLL;
typedef std::pair <int, int> PII;
typedef std::pair <PII, int> PIII;
typedef std::pair <LL, LL> PLL;



#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR(i,a,b,jump) for(int i=a; i<=b; i+=jump)
#define PB push_back
#define MP make_pair
#define prime first.first
#define exponent first.second
#define powerOfPrime second 



VI linear_sieve(int n){ // we find primes x (using linear sieve), for x in {0,1,2,...,n} and  MAX_N >= n >= 2
	
	// isPrime[x] = false iff x is not prime
	// isPrime[x] = true  iff x is     prime
	VB isPrime(n+1, true); // initially, all numbers 0, 1, ..., n are primes...
	isPrime[0] = isPrime[1] = false; // ...but 0 and 1 are not primes
	
	// ---------------------
	
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
	
	// ---------------------
	
	VI res;
	REP(i,2,n){
		if( isPrime[i] == true ){ // if "i" is prime
			res.PB(i); // we've found a new prime numner "i"
		}
	}
	
	// ---------------------
	
	isPrime.clear();
	
	// ---------------------
	
	return res;
	
}



// a mod b, where a - any integer, b - any non-zero integer
LL mod(LL a, LL b){
	return ( a >= 0 )  ?  ( a - ( ( a / std::abs(b) ) * std::abs(b) ) )  :  ( a + ( ( ( std::abs(a) + std::abs(b) - 1 ) / std::abs(b) ) * std::abs(b) ) )  ;
}



// a*b (mod m).
// Assumption 1: a,b,m - integers
// Assumption 2: m != 0
LL multiply_modulo(LL a, LL b, LL m){
	
	a = mod(a, m);
	b = mod(b, m);
	// from now: a, b >= 0
	
	LL res = 0;
	
	while ( b > 0 ){
		if( b % 2 == 1 ){
			res = mod( res+a, m );
		}
		
		a = mod( a+a, m );
		
		b /= 2;
	}
	
	return res % m;
}



// a^k (mod m).
// Assumption 1: a,k,m - integers; 
// Assumption 2: m != 0
// Assumption 3: k >= 0
LL fast_power_modulo(LL a, LL k, LL m){
	
	a = mod(a, m);
	
	LL res = mod(1, m);
	
	while ( k > 0 ){
		if( k % 2 == 1 ){
			res = multiply_modulo(res, a, m);
		}
		
		a = multiply_modulo(a, a, m);
		
		k /= 2;
	}
	
	return res; 
}



// We find an exponent for a prime number "p" in factorization of "n!"
int find_exponent(int n, int p){
	LL P = p; // P = p^k (initially, k=1)
	int res = 0; //
	
	while( P <= n ){
		res += n/P; 
		
		P *= p; // p^(k+1)
	}
	
	return res;
}



LL N_choose_K_mod_M(LL n, LL k, LL m){
	
	if( n < 0 or k < 0 or n < k ){
		return 0;
	}
	
	if( n < 2 ){
		return mod(1, m);
	}
	
	// From now: n >= 2
	
	VI primes = linear_sieve( n );
	
	VI exponents( primes.size(), 0 );
	REP(i,0,primes.size()-1){
		exponents[i] += find_exponent( n, primes[i] );
		exponents[i] -= find_exponent( k, primes[i] );
		exponents[i] -= find_exponent( n-k, primes[i] );
	}
	
	LL res = mod(1, m);
	if( res == 0 ){
		return res;
	}
	
	REP(i,0,primes.size()-1){
		res = mod(   multiply_modulo( res,   fast_power_modulo( primes[i], exponents[i], m ),   m ),   m   ); // res = ( res * ( p^exp ) ) (mod m)
		
		if( res == 0 ){
			return res;
		}
	}
	
	return res;
}



int main(){
	
	int n, k;
	LL m;
	
	// ----------------
	
	printf( "We'll find (n choose k) (mod m).\n\nData input\nEnter n (-9*10^18 <= n <= 3*10^7):\nn = " );
	scanf( "%d", &n );
	
	// ----------------
	
	printf( "\nEnter k (-9*10^18 <= k <= 9*10^18):\nk = " );
	scanf( "%d", &k );
	
	// ----------------
	
	printf( "\nEnter m (-4.5*10^18 <= m <= 4.5*10^18, m != 0):\nm = " );
	scanf( "%lld", &m );
	
	// ----------------
	
	printf(   "\n\nResult:\n(%d choose %d) (mod %lld) = %lld\n", n, k, m, N_choose_K_mod_M(n, k, m)   );
	
	// ----------------
	
	return 0;
}
