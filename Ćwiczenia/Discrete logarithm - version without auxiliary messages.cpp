/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Finding a dicrete logarithm. 
	Given integers a,b,n (a,b>=0, n>0), we want to find such a minimal positive integer x that a^x = b (mod n).
	Note 1. I assume that if a=0, then a^0 = 1 (mod n) and a^x = 0 (mod n) for x>0.
	Note 2. If b = 1, then we can say that x=0 is a solution. Nevetherless, we want to find a non-trivial (positive integer) solution.
	
	Complexity:
		Time: O( sqrt(n) )
		Space: O( sqrt(n) )

*/

#include<bits/stdc++.h>


typedef long long LL;
typedef std::unordered_map < LL, LL > HASH_MAP;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define remainder first
#define exponent second


// Finding max exp >= 0: 2^exp <= x.
LL f(LL x){
	LL exp = 0, power_of_2 = 1; // power_of_2 = 2^exp
	while( power_of_2 <= x ){
		power_of_2 *= 2;
		++exp;
	}
	
	return exp - 1;
}


// a*b (mod m).
// Assumption 1: a,b,m - integers >= 0
// Assumption 2: m != 0
/*
LL multiply_modulo(LL a, LL b, LL m){
	
	a = a % m;
	b = b % m;
	
	LL res = 0;
	
	while ( b > 0 ){
		if( b % 2 == 1 ){
			res = (res + a) % m;
		}
		
		a = (a + a) % m;
		
		b /= 2;
	}
	
	return res % m;
}
*/


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


// Finding such non-negative x that a*x = b (mod n) or returning (-1) if no solution
LL find_matching_remainder(LL a, LL b, LL n){
	LL gcd_a_b = gcd(a, b);
	LL gcd_a_b_n = gcd( n, gcd_a_b ); // gcd(a,b,n) = gcd( n, gcd(a,b) )
	
	a /= gcd_a_b_n;
	b /= gcd_a_b_n;
	n /= gcd_a_b_n;
	
	if( gcd(a, n) == 1 ){ // if a, n - coprimes
		return (inv(a, n) * b) % n; // { [ a^(-1) (mod n) ] * b } (mod n) 
	}
	
	return -1; // no solution
}


// Generating all possible remainders from a given map of remainders.
HASH_MAP generate_remainders(HASH_MAP remainders, LL n){
	
	HASH_MAP res; // a result of this function
	
	if( remainders.size() > 0 ){ // if we have anything to process
		
		HASH_MAP::iterator remainders_it = remainders.begin(); // current element from an input map "remainders"
		
		res[ remainders_it -> remainder ] = remainders_it -> exponent;
		++remainders_it;
	
	
		while( remainders_it != remainders.end() ){
			
			HASH_MAP tmp_res( res ); // temporary map
			
			
			// we match the current element from an input map "remainders" with all elements from a temporary map "tmp_res"
			for(HASH_MAP::iterator it = tmp_res.begin(); it != tmp_res.end();  ++it){
				
				LL tmp_remainder = (   (remainders_it -> remainder) * (it -> remainder)   ) % n;
				LL tmp_exponent = (remainders_it -> exponent) + (it -> exponent);
				
				if( tmp_res.count( tmp_remainder ) > 0 ){
					res[ tmp_remainder ] = std::min( res[ tmp_remainder ], tmp_exponent );
				}
				else{
					res[ tmp_remainder ] = tmp_exponent;
				}
			}
			
			
			tmp_res.clear();
			
			
			// we consider only the current element from a map "remainders"
			LL tmp_remainder = remainders_it -> remainder;
			LL tmp_exponent = remainders_it -> exponent;
			
			if( res.count( tmp_remainder ) > 0 ){
				res[ tmp_remainder ] = std::min( res[ tmp_remainder ], tmp_exponent );
			}
			else{
				res[ tmp_remainder ] = tmp_exponent;
			}
			
			
			++remainders_it; // we go to next element from an input map "remainders"
		}	
	}
	
	
	return res;
}



// Finding a discrete logarithm.
// This function returns a smallest result x > 0 (if a solution found) or x = -1 (if a discrete logarithm doesn't exist).
LL discrete_logarithm(LL a, LL b, LL n){
	
	a %= n;
	b %= n;
	
	
	// --------------------------
	
	
	// max k: 2^k <= n
	LL max_k = f( n + 10 ); // for safety, an argument is noticeably bigger than n
	
	
	// --------------------------
	
	
	/* Generating two maps of remainders (each element has a form a^(2^k) mod n, where 0 <= k <= max_k ) */
	HASH_MAP remainders1, remainders2;
	
	// remainders1
	LL exp = 1; // exp = 2^k (initially, k=0)
	LL tmp_remainder = a; // tmp_remainder = a^(exp) (mod n)
	remainders1[tmp_remainder] = exp;
	
	LL tmp;
	REP(k,1,max_k/2){
		tmp = (tmp_remainder * tmp_remainder) % n; // a^(2^(k+1)) (mod n)
		
		if( tmp_remainder != tmp ){ // we are not in fixed point
			tmp_remainder = tmp;
			exp *= 2;
			
			if(  remainders1.find(tmp_remainder) == remainders1.end()  ){ // if we have a brand-new remainder
				remainders1[tmp_remainder] = exp; // tmp_remainder = a^(2^(k+1)) (mod n)	
			}
		}
		else{ // we are in fixed point
			goto z;
		}
	}
	
	
	// remainders2
	REP(k,(max_k/2)+1,max_k){
		tmp = (tmp_remainder * tmp_remainder) % n; // a^(2^(k+1)) (mod n)
		
		if( tmp_remainder != tmp ){ // we are not in fixed point
			tmp_remainder = tmp;
			exp *= 2;
			
			if(  remainders1.find(tmp_remainder) == remainders1.end()   and   remainders2.find(tmp_remainder) == remainders2.end()  ){ // if we have a brand-new remainder 
				remainders2[tmp_remainder] = exp; // tmp_remainder = a^(2^(k+1)) (mod n)	
			}
		}
		else{ // we are in fixed point
			goto z;
		}
	}
	
	z: ;
	
	
	// --------------------------
	
	
	/* Generating all possible remainders from given remainders' maps. */
	
	HASH_MAP map_remainders1 = generate_remainders( remainders1, n );
	HASH_MAP map_remainders2 = generate_remainders( remainders2, n );
	
	
	// --------------------------
	
	
	/* Finding a discrete logarithm - our result */
	
	bool found_solution_in_1st_map = false;
	LL INF = n + 100; // infinity
	LL res = INF; // discrete logarithm - our result
	
	// 1st map
	HASH_MAP::iterator it1 = map_remainders1.find( b );
	
	if( it1 != map_remainders1.end() ){
		found_solution_in_1st_map = true;
		
		res = std::min( res, it1 -> exponent );
	}
	
	
	
	// 2nd map
	if( found_solution_in_1st_map == false ){ // if no solution found in 1st map
		HASH_MAP::iterator it2 = map_remainders2.find( b );
		
		if( it2 != map_remainders2.end() ){
			
			if( res > it2 -> exponent ){
				res = it2 -> exponent;
			}
		}	
	}
	
	
	
	// one remainder is from the 1st map, the second one remainder is from the 2nd map
	if( found_solution_in_1st_map == false ){ // if no solution found in 1st map
		
		for(HASH_MAP::iterator it1 = map_remainders1.begin(); it1 != map_remainders1.end();  ++it1){
		
			LL matching_remainder = find_matching_remainder( it1->first, b, n );
			
			if( matching_remainder != -1 ){ // if a solution exists
				
				HASH_MAP::iterator it2 = map_remainders2.find( matching_remainder ) ;
			
				if( it2 != map_remainders2.end() ){ // if found a matching remainder successively
					res = std::min( res, (it1->exponent) + (it2->exponent) );
				}	
			}
		}
	}
	
	
	// --------------------------
	
	
	return ( res == INF ) ? -1 : res ; // if no solution found, return -1, otherwise return result
}



int main(){
	
	LL a, b, n;
	printf( "We want to find such a positive integer x that a^x = b (mod n).\n\nData input\nEnter a base of power (0 <= a <= 9*10^18):\na = " );
	scanf( "%lld", &a );
	
	printf( "\nEnter an expected remainder b (0 <= b <= 9*10^18):\nb = " );
	scanf( "%lld", &b );
	
	printf( "\nEnter a modulo (1 <= n <= 10^9):\nn = " );
	scanf( "%lld", &n );
	
	// -------------------------
	
	LL x = discrete_logarithm(a, b, n);
	
	// -------------------------
	
	if( x == -1 ){ // no solution
		printf( "\nNo solution\n" );
	}
	else{
		printf( "\nThe result: x = %lld\n", x );
	}
	
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

*/
