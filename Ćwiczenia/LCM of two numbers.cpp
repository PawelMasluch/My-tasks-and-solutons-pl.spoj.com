/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Computing LCM of two positive integers (C++, Windows).

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



int main(){
	
	LL a, b;
	
	printf( "Data input\n" );
	
	printf( "Enter first number: a = " );
	scanf( "%lld", &a );
	
	printf( "Enter second number: b = " );
	scanf( "%lld", &b );
	
	// ---------------------
	
	printf( "\nResult:\n" );
	
	// LCM(a,b)
	printf( "LCM(%lld, %lld) = %lld\n", a, b, LCM(a, b) );
	
	// ---------------------
	
	return 0;
}
