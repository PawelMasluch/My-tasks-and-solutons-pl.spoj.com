/*

Copyright (C) Pawel Masluch, 2021. All rights reserved.

Extended Euclidean algorithm.
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
	
*/

#include<bits/stdc++.h>


typedef long long LL;


void extended_Euclidean_algorithm(LL a, LL b, LL &u, LL &v, LL &w, LL &x, LL &y, LL &z){
	
	/* Initialization */
	// 1. equation
	u = 1;	v = 0;	w = a;
	// 2. equation
	x = 0;	y = 1;	z = b;
	
	
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
}


int main(){
	
	LL a, b, u, v, w, x, y, z;
	
	// --------------------------
	
	printf( "Data input\n" );
	
	printf( "a = " );
	scanf( "%lld", &a );
	
	printf( "b = " );
	scanf( "%lld", &b );
	
	// --------------------------
	
	extended_Euclidean_algorithm(a, b, u, v, w, x, y, z);
	
	// --------------------------
	
	printf( "\nResults:\n" );
	
	printf( "1. equation: (%lld)*(%lld) + (%lld)*(%lld) = %lld\n", a, u, b, v, w );
	printf( "2. equation: (%lld)*(%lld) + (%lld)*(%lld) = %lld\n", a, x, b, y, z );
	
	// --------------------------
	
	return 0;
}
