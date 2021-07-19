/*
	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Finding such non-negative x that a*x = b (mod n) or reporting that there is no solution.
*/


#include<bits/stdc++.h>


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


// a*b (mod m).
// Assumption 1: a,b,m - non-negative integers
// Assumption 2: m != 0
LL multiply_modulo(LL a, LL b, LL m){
	
	a = a % m;
	b = b % m;
	
	LL res = 0;
	
	while ( b > 0 ){
		if( b % 2 == 1 ){
			res = (res+a) % m;
		}
		
		a = (a+a) % m;
		
		b /= 2;
	}
	
	return res % m;
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


// Finding such non-negative x that a*x = b (mod n) or returning (-1) if no solution.
LL find_matching_remainder(LL a, LL b, LL n){
	LL gcd_a_b = gcd(a, b);
	LL gcd_a_b_n = gcd( n, gcd_a_b ); // gcd(a,b,n) = gcd( n, gcd(a,b) )
	
	a /= gcd_a_b_n;
	b /= gcd_a_b_n;
	n /= gcd_a_b_n;
	
	if( gcd(a, n) == 1 ){ // if a, n - coprimes
		return multiply_modulo( inv(a, n), b, n ); // { [ a^(-1) (mod n) ] * b } (mod n) 
	}
	
	return -1; // no solution
}


int main(){
	
	LL a, b, n;
	printf( "We want to find such a non-negative integer x that a*x = b (mod n).\n\nData input\nEnter a base of power (1 <= a <= 4.5*10^18):\na = " );
	scanf( "%lld", &a );
	
	printf( "\nEnter an expected remainder b (0 <= b <= 4.5*10^18):\nb = " );
	scanf( "%lld", &b );
	
	printf( "\nEnter a modulo (1 <= n <= 4.5*10^18):\nn = " );
	scanf( "%lld", &n );
	
	// -------------------------
	
	LL x = find_matching_remainder(a, b, n);
	
	// -------------------------
	
	if( x == -1 ){ // no solution
		printf( "\nNo solution\n" );
	}
	else{
		printf( "\nThe result: x = %lld\n", x );
	}
	
	return 0;
}
