/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Computing LCM of set of positive integers (C++, Windows).

*/

#include<bits/stdc++.h>



typedef long long LL;



// GCD(a,b) - the greatest integer dividing both integer a and integer b
// GCD(0,0) case is undefined (the greatest integer dividing both 0 and 0 doesn't exist)
// Because GCD(a,b) = GCD(|a|, |b|), I assume (without loss of generality) that a,b >= 0; I also assume that !(a = 0 and b = 0) (to avoid undefined case)

// LCM(a,b) - the smallest positive integer which is divisible both (and separetely considered) by integer a and by integer b
// Property: LCM(a,b) = ( a/GCD(a,b) ) * b
// LCM(a,0) and LCM(0,b) cases are undefined (because the hypothetical result would have to be divisible by zero)
// Because LCM(a,b) = LCM(|a|, |b|), I assume (without loss of generality) that a,b >= 0; I also assume that (a != 0 and b != 0) (to meet the assumption: a,b>0) 






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





// 3*10^9 >= a,b > 0

// LCM(a,b) = ( a/GCD(a,b) ) * b
LL LCM(LL a, LL b){
	return ( a/GCD(a,b) ) * b;
}



#define REP(i,n) for(int i=0; i<n; ++i)


// 10^6 >= n >= 0
// t[i] > 0 for i=0,1,...,n-1
// Numbers' set satisfies LCM(t[0],...,t[n-1]) <= 9*10^18
// Obviously, by definition, LCM(t[0],...,t[n-1]) > 0
LL LCM_of_numbers_set(LL *t, LL n){
	
	LL res = 1; // LCM of an empty set, by definition
	
	REP(i,n){
		res = LCM( res, t[i] );	
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
	
	// LCM(a,b)
	printf( "LCM for our set is %lld\n", LCM_of_numbers_set(t, n) );
	
	// ---------------------
	
	if(n > 0){
		delete [] t;
	}
	
	return 0;
}
