/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Finding a dicrete logarithm using baby-step giant-step algorithm. 
	Given integers a,b,n (a,b>=0, n>0), we want to find such a minimal positive integer x that a^x = b (mod n).
	Assumption 1: a, n - coprimes (in other words: gcd(a,n) = 1)
	Note 1. I assume that if a=0, then a^0 = 1 (mod n) and a^x = 0 (mod n) for x>0.
	Note 2. If b = 1, then we can say that x=0 is a solution. Nevetherless, we want to find a non-trivial (positive integer) solution.
	
	Complexity:
		Time: O( sqrt(n) )
		Space: O( sqrt(n) )
		
	Bibliography:
		1. https://www.youtube.com/watch?v=007MVsELvQw

*/

#include<bits/stdc++.h>


typedef long long LL;
typedef std::unordered_map < LL, LL > HASH_MAP;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define PB push_back
#define MP std::make_pair
#define remainder first
#define exponent second


// Finding max k>=0: k^2 <= x.
// 9*10^18 >= x >= 0.
// Time complexity: O( sqrt(n) ).
// Space complexity: O( 1 ).
LL floor_sqrt(LL x){
	
	LL res = 0;
	while( res*res <= x ){
		++res;
	}
	
	return res - 1;
}


// a^k (mod n).
// Assumption 1: a,k,n - integers; 
// Assumption 2: n != 0
// Assumption 3: k >= 0
LL fast_power_modulo(LL a, LL k, LL n){
	
	a %= n;
	
	LL res = 1 % n;
	
	while ( k > 0 ){
		if( k % 2 == 1 ){
			res = (res * a) % n;
		}
		
		a = (a * a) % n;
		
		k /= 2;
	}
	
	return res; 
}


// 9*10^18 >= a,b >= 0 and a+b > 0

// gcd (a,b) = a (if b = 0) or 
// gcd(a,b) = gcd(b, a mod b) (if b != 0)
LL gcd(LL a, LL b){
	
	LL tmp;
	while( b != 0 ){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	
	return a;
}


// Finding (via extended Euclidean algorithm) such a non-negative integer u that a*u + b*v = 1 (mod b).
// In other words, we find u = a^(-1) (mod b).
// Obviously, a,b - coprimes (otherwise, an inverse doesn't exist).
LL inv(LL a, LL b){
	
	/* Initialization */
	// 1. equation
	LL u = 1,	v = 0,	w = a;
	// 2. equation
	LL x = 0,	y = 1,	z = b;
	
	
	if( w < z ){ // we change the equations' order
		std::swap( u, x );
		std::swap( v, y );
		std::swap( w, z );
	}
	
	
	LL q;
	while( z != 0 ){
		
		q = w / z;
		
		// (1. equation) - q * (2. equation) 
		u -= q*x;
		v -= q*y;
		w -= q*z;
		
		
		// we change the equations' order
		std::swap( u, x );
		std::swap( v, y );
		std::swap( w, z );
	}
	
	if( u < 0 ){
		u += b; // we want a non-negative solution
	}
	
	return u;
}


// Finding a discrete logarithm using baby-step giant-step algorithm.
// Given integers a,b,n (a,b>=0, n>0), we want to find such a minimal positive integer x that a^x = b (mod n).
// This function returns a smallest result x > 0 (if a solution found) or x = -1 (if a discrete logarithm doesn't exist) or x=-2 (if a,n are not coprimes).
LL baby_step_giant_step_discrete_logarithm(LL a, LL b, LL n){
	
	if( gcd(a, n) != 1 ){
		//printf( "Numbers a=%lld and n=%lld are not coprimes (the assumption is not satisfied) - I finish the function.\n", a, n );
		return -2; // error code: a,n are not coprimes
	}
	
	a %= n;
	b %= n;
	
	
	// --------------------------
	
	
	// max k: k^2 <= n
	LL k = floor_sqrt( n );
	//printf( "\n\nk = %lld\n", k );
	
	
	// --------------------------
	
	
	/* Generating two maps of remainders. */
	HASH_MAP baby_remainders, giant_remainders;
	
	// baby_remainders
	LL curr_remainder = a;
	REP(exp,1,k-1){
		if( baby_remainders.find( curr_remainder ) == baby_remainders.end() ){ // we have a brand-new remainder now
			baby_remainders[ curr_remainder ] = exp;	
		}
		
		curr_remainder = (curr_remainder * a) % n;
	}
	
	
	/*
	printf( "\n\nbaby_remainders:\n" );
	for(auto baby_it: baby_remainders){
		printf( "(%lld, %lld)\n", baby_it.remainder, baby_it.exponent );
	}
	*/
	
	
	
	
	// giant_remainders
	LL inv_a = inv(a, n); // a^(-1) (mod n)
	LL a_to_minus_kth_power = fast_power_modulo( inv_a, k, n ); // a^(-k) (mod n)
	curr_remainder = (b * a_to_minus_kth_power) % n; // [ b * a^(-k) ] (mod n)
	
	LL r = 1;
	while( r*k <= n ){
		if( giant_remainders.find( curr_remainder ) == giant_remainders.end() ){ // we have a brand-new remainder now
			giant_remainders[ curr_remainder ] = r*k;	
		}
		
		curr_remainder = (curr_remainder * a_to_minus_kth_power) % n;
		++r;
	} // now: "r" is minmimum positive integer such that r*k > n
	
	if( giant_remainders.find( curr_remainder ) == giant_remainders.end() ){ // we have a brand-new remainder now
		giant_remainders[ curr_remainder ] = r*k;	
	}
	
	
	/*
	printf( "\n\ngiant_remainders:\n" );
	for(auto giant_it: giant_remainders){
		printf( "(%lld, %lld)\n", giant_it.remainder, giant_it.exponent );
	}
	*/
	
	
	
	// --------------------------
	
	
	/* Finding a discrete logarithm - our result */
	
	
	LL INF = n + 100; // infinity
	LL res = INF; // infinity
	
	
	// finding a remainder "b" in map "baby_remainders"
	auto baby_it = baby_remainders.find( b );
	if( baby_it != baby_remainders.end() ){
		res = std::min( res, baby_it -> exponent );
	}
	
	
	// finding a remainder "b" in map "giant_remainders"
	auto giant_it = giant_remainders.find( b );
	if( giant_it != giant_remainders.end() ){
		res = std::min( res, giant_it -> exponent );
	}
	
	
	// matching remainders in both maps
	for(auto const& baby_it: baby_remainders ){
		
		//printf( "\nA current remainder in baby_remainders is %lld, ", baby_it.remainder );
		
		auto giant_it = giant_remainders.find( baby_it.remainder );
		
		if( giant_it != giant_remainders.end() ){
			//printf( " a candidate for a result is %lld, ", baby_it.exponent + giant_it -> exponent );
			res = std::min( res, baby_it.exponent + giant_it -> exponent );
			//printf( " a current result is %lld\n\n", res );
		}
		/*else{
			printf( "this remainder doesn't exist in giant_remainders\n\n" );
		}*/
	}
	
	
	// --------------------------
	
	
	return ( res == INF ) ? -1 : res; // if no solution found, return -1, otherwise return result
}



int main(){
	
	LL a, b, n;
	printf( "We want to find (using baby-step giant-step algorithm) such a positive integer x that a^x = b (mod n).\nRemind: a,n must be coprimes.\n\nData input\nEnter a base of power (0 <= a <= 9*10^18):\na = " );
	scanf( "%lld", &a );
	
	printf( "\nEnter an expected remainder b (0 <= b <= 9*10^18):\nb = " );
	scanf( "%lld", &b );
	
	printf( "\nEnter a modulo (1 <= n <= 10^9):\nn = " );
	scanf( "%lld", &n );
	
	// -------------------------
	
	LL x = baby_step_giant_step_discrete_logarithm(a, b, n);
	
	// -------------------------
	
	if( x == -2 ){ // error code
		printf( "\nError: numbers a = %lld and n = %lld are not coprimes (the assumption in algorithm is not satisfied).\nNevertheless, a discrete logarithm may exist but this algorithm is unable to find it.\n", a, n );
		return 0;
	}
	
	if( x == -1 ){ // no solution
		printf( "\nNo solution\n" );
		return 0;
	}
	
	
	printf( "\nThe result: x = %lld\n", x );
	return 0;
}


/*

Test #1:
In: 
5 
3 
109
Out:
22


Test #2:
In: 
17 
67
118
Out:
No solution


Test #3:
In: 
7
1 
148
Out:
18


Test #4:
In: 
5
14 
37
Out:
3


Test #5:
In: 
11
1 
12
Out:
2


Test #6:
In: 
5
8 
13
Out:
3


Test #7:
In: 
6
7 
13
Out:
7


Test #8:
In: 
45
56
167
Out:
32


Test #9:
In: 
5
6
7
Out:
3


Test #9:
In: 
104
106
107
Out:
53


Test #10:
In: 
113
5
999979
Out:
880684


Test #11:
In: 
6
7
113
Out:
104


Test #12:
In:
5 
6
117
Out:
20


Test #13:
In:
113 
2
997
Out:
267


Test #14:
In:
5
4
157
Out:
126

*/
