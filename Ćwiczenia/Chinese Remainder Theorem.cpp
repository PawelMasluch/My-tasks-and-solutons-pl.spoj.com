/*

Copyright (C) Pawel Masluch, 2021. All rights reserved.

I. Extended Euclidean algorithm.
For given non-negative integers a, b, we find integers u, v, w, x, y, z such that: 
	1. a*u + b*v = GCD(a,b) (if a=b=0, then GCD(a,b) = 0, by definition)
	2. a*x + b*y = 0
Additionally:
	1.if GCD(a,b) = 1 and a,b > 0, then u = a^(-1) (mod b) and v = b^(-1) (mod a).
	2. if (u0, v0) satisfy equation 1. (a*u0 + b*v0 = GCD(a,b)), then
		  ( u,  v) := (u0 - k*b, v0 + k*a) (k is arbitrary integer) also satisfy equation 1. (a*u + b*v = GCD(a,b)).
	
Bibliography:
	1. http://wmii.uwm.edu.pl/~bostar/PF/PFlab4.pdf
	2. https://pl.wikibooks.org/wiki/Kody_%C5%BAr%C3%B3d%C5%82owe/Algorytm_Euklidesa
	3. https://eduinf.waw.pl/inf/alg/001_search/0009.php
	4. https://pl.wikipedia.org/wiki/Algorytm_Euklidesa
	5. http://wazniak.mimuw.edu.pl/index.php?title=Matematyka_dyskretna_1/Wyk%C5%82ad_10:_Teoria_liczb#Rozszerzenie_algorytmu_Euklidesa.
	6. http://www.algorytm.org/algorytmy-arytmetyczne/rozszerzony-algorytm-euklidesa.html
	7. https://www.youtube.com/watch?v=_jrD08bi480
	
	
II. Chinese Remainder Theorem
Given a system of k (k >= 1) congruences:
	x = a[i] ( mod n[i] ) (i = 1,...,k).
We find the smallest non-negative x satisfying above constraints (a[i] and n[i], for i=1,...,k are given).
Assumptions: 
	1. If 1 <= i < j <= k, then gcd( n[i], n[j] ) = 1.
	2. n[i] > 0 for i=1,...,k.
	3. 0 <= a[i] < n[i] for i=1,...,k.

Constraint:
	1. The product of all values n[i] <= 10^18 
	   (this implies k <= 15 because a product of 15 smallest primes is < 10^18 but a product of 16 smallest primes is > 10^18).
	   
Bibliography:
	1. https://en.wikipedia.org/wiki/Chinese_remainder_theorem
	
*/

#include<bits/stdc++.h>


typedef long long LL;


// Reverse modulo ( a^(-1) (mod n) ) via extended Euclidean algorithm.
// a,n > 0 and gcd(a,n) = 1.
// We find u,v such that a*u + n*v = gcd(a,n) = 1 (our result is hidden in variable u).
LL reverse_modulo(LL a, LL n){
	
	LL u, v, w, x, y, z;
	
	/* Initialization */
	// 1. equation
	u = 1;	v = 0;	w = a;
	// 2. equation
	x = 0;	y = 1;	z = n;
	
	
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
		
		
		if( w < z ){ // we change the equations' order
			std::swap( u, x );
			std::swap( v, y );
			std::swap( w, z );
		}
	}
	
	return (u >= 0) ? u: u+n; // the result is in variable "u"
}


// a*b (mod n)
// 4.5*10^18 >= a,b >= 0
// 9*10^18 >= n >= 1
LL multiply_modulo(LL a, LL b, LL n){
	LL res = 0;
	
	while( b != 0 ){
		if( b % 2 == 1 ){
			res = (res + a) % n;
		}
		
		a = (a + a) % n;
		b /= 2;
	}
	
	return res;
}


#define REP(i,a,b) for(int i=a; i<=b; ++i)


LL Chinese_Remainder_Theorem(LL *a, LL *n, int k){
	
	LL N = 1;
	REP(i,0,k-1){
		N *= n[i];
	}
	
	// -----------------
	
	LL N_i, M_i, x = 0;
	REP(i,0,k-1){
		N_i = N / n[i];
		
		M_i = reverse_modulo( N_i, n[i] ); // M_i = (N_i)^(-1)( mod n[i] )
		
		x = (      x   +   multiply_modulo(   a[i], multiply_modulo( M_i, N_i, N ), N   )      ) % N; // x = (x + a[i] * M_i * N_i ) mod N
	}
	
	// -----------------
	
	return x;
}


int main(){
	
	int k;
	LL *a, *n;
	
	// --------------------------
	
	printf( "Data input\n" );
	
	printf( "Enter a number of congruence equations:\nk = " );
	scanf( "%d", &k );
	
	a = new LL [k];
	n = new LL [k];
	
	printf( "Enter the congruence equations:\n" );
	REP(i,0,k-1){
		scanf( "%lld %lld", &a[i], &n[i] );
	}
	
	// --------------------------
	
	LL x = Chinese_Remainder_Theorem(a, n, k);
	
	// --------------------------
	
	printf( "\nResult:\n" );
	
	printf( "The solution is x = %lld\n", x );
	
	// --------------------------
	
	delete [] a;
	delete [] n;
	
	// --------------------------
	
	return 0;
}

/*

Test #1:
In:
7
1 2
1 3
2 5
1 7
4 11
6 13
8 17
Out:
300007

Test #2:
3
1 2
1 3
3 17
Out:
37

Test #3:
1
100 106
Out:
100

*/
