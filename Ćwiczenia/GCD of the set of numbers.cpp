/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Computing GCD of two non-negative integers (at least one of them is strictly positive) in dirrefent ways (C++, Windows).
	
	Bibliography:
		1. https://eduinf.waw.pl/inf/alg/001_search/0006.php

*/

#include<bits/stdc++.h>



typedef long long LL;



// GCD(a,b) - the greatest integer dividing both integer a and integer b
// GCD(0,0) case is undefined (the greatest integer dividing both 0 and 0 doesn't exist)
// Because GCD(a,b) = GCD(|a|, |b|), I assume (without loss of generality) that a,b >= 0; I also assume that !(a = 0 and b = 0) (to avoid undefined case)



// 9*10^18 >= a,b >= 0 and a+b > 0

// GCD (a,b) = a (if b = 0) or 
// GCD(a,b) = GCD(b, a mod b) (if b != 0)
LL GCD(LL a, LL b){
	
	LL tmp;
	while( b != 0 ){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	
	return a;
}



#define REP(i,n) for(int i=0; i<n; ++i)



// 10^6 >= n >= 0
// 9*10^18 >= t[i] >= 0 for i=0,1,...,n-1
// t[0] + ... + t[n-1] > 0
// Numbers' set satisfies LCM(t[0],...,t[n-1]) <= 9*10^18
// Obviously, by definition, LCM(t[0],...,t[n-1]) > 0
LL GCD_of_numbers_set(LL *t, LL n){
	
	LL res = 0; // GCD of an empty set, by definition
	
	REP(i,n){
		res = GCD( res, t[i] );	
	}
	
	return res;
}



int main(){
	
	LL n, *t;
	
	printf( "Data input\n" );
	
	printf( "Enter a number of elements in set: n = " );
	scanf( "%lld", &n );
	
	if(n > 0){
		
		t = new LL [n];
		
		printf( "Enter a set of numbers:\n" );
		REP(i,n){
			scanf( "%lld", &t[i] );
		}
	}
	
	// ---------------------
	
	printf( "\nResult:\n" );
	
	// GCD(a,b)
	printf( "GCD for our set is %lld\n", GCD_of_numbers_set(t, n) );
	
	// ---------------------
	
	if(n > 0){
		delete [] t;
	}
	
	return 0;
}
