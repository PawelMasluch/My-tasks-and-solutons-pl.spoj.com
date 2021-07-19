/*

	Copyright (C) Pawel Masluch, 2021. All rights reserved.
	
	Computing GCD of two non-negative integers (at least one of them is strictly positive) in dirrefent ways (C++, Windows).
	
	Bibliography:
		1. https://eduinf.waw.pl/inf/alg/001_search/0006.php
		2. https://en.wikipedia.org/wiki/Euclidean_algorithm (especially, section "Method of least absolute remainders")

*/

#include<bits/stdc++.h>



typedef long long LL;



// GCD(a,b) - the greatest integer dividing both integer a and integer b
// GCD(0,0) case is undefined (the greatest integer dividing both 0 and 0 doesn't exist)
// Because GCD(a,b) = GCD(|a|, |b|), I assume (without loss of generality) that a,b >= 0; I also assume that !(a = 0 and b = 0) (to avoid undefined case)



// 9*10^18 >= a,b >= 0 and a+b > 0

// GCD (a,b) = a (if b = 0) or 
// GCD(a,b) = GCD(b, a) (if a < b) or 
// GCD(a,b) = GCD(a-b, b) (if a >= b)
LL brutal_recursive_GCD(LL a, LL b){
	if( b == 0 ){
		return a;
	}
	else{
		if( a < b ){
			return brutal_recursive_GCD(b, a);
		}
		else{
			return brutal_recursive_GCD(a-b, b);
		}
	}
}



// 9*10^18 >= a,b >= 0 and a+b > 0

// GCD (a,b) = a (if b = 0) or 
// GCD(a,b) = GCD(b, a) (if a < b) or 
// GCD(a,b) = GCD(a-b, b) (if a >= b)
LL brutal_iterational_GCD(LL a, LL b){
	
	LL tmp;
	while( b != 0 ){
		
		if( a < b ){ // GCD(b, a)
			
			// swap(a, b)
			tmp = a;
			a = b;
			b = tmp;
		}
		
		a -= b; // GCD(a-b, b)
	}
	
	return a; // GCD(a, 0)
}



// 9*10^18 >= a,b >= 0 and a+b > 0

// GCD (a,b) = a (if b = 0) or 
// GCD(a,b) = GCD(b, a mod b) (if b != 0)
LL classic_recursive_GCD(LL a, LL b){
	return (b == 0) ? a : classic_recursive_GCD(b, a%b);
}



// 9*10^18 >= a,b >= 0 and a+b > 0

// GCD (a,b) = a (if b = 0) or 
// GCD(a,b) = GCD(b, a mod b) (if b != 0)
LL classic_iterational_GCD(LL a, LL b){
	
	LL tmp;
	while( b != 0 ){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	
	return a;
}



// 9*10^18 >= a,b >= 0 and a+b > 0
// GCD(a, 0) = a or
// GCD(0, b) = b or
// GCD(a, b) = 2*GCD(a/2, b/2) (if a mod 2 = b mod 2 = 0) or
// GCD(a, b) = GCD(a/2, b) (if a mod 2 = 0 and b mod 2 = 1) or
// GCD(a, b) = GCD(a, b/2) (if a mod 2 = 1 and b mod 2 = 0) or
// GCD(a, b) = GCD((a-b)/2, b) (if a mod 2 = b mod 2 = 1 and  a >= b) or
// GCD(a, b) = 2*GCD(a, (b-a)/2) (if a mod 2 = b mod 2 = 1 and a < b)
LL binary_recursive_GCD(LL a, LL b){
	
	if( a == 0 ){
		return b;
	}
	//else{
		if( b == 0 ){
			return a;
		}
		//else{
			if( a%2 == 0  &&  b%2 == 0 ){
				return 2 * binary_recursive_GCD(a/2, b/2);
			}
			//else{
				if( a%2 == 0  &&  b%2 == 1 ){
					return binary_recursive_GCD(a/2, b);
				}
				//else{
					if( a%2 == 1  &&  b%2 == 0 ){
						return binary_recursive_GCD(a, b/2);
					}
					//else{
						if( a%2 == 1  &&  b%2 == 1  && a >= b ){
							return binary_recursive_GCD((a-b)/2, b);
						}
						//else{
							if( a%2 == 1  &&  b%2 == 1  && a < b ){
								return binary_recursive_GCD(a, (b-a)/2);
							}
						/*}
					}
				}
			}
		}
	}*/
}



// 9*10^18 >= a,b >= 0 and a+b > 0
// GCD(a, 0) = a or
// GCD(0, b) = b or
// GCD(a, b) = 2*GCD(a/2, b/2) (if a mod 2 = b mod 2 = 0) or
// GCD(a, b) = GCD(a/2, b) (if a mod 2 = 0 and b mod 2 = 1) or
// GCD(a, b) = GCD(a, b/2) (if a mod 2 = 1 and b mod 2 = 0) or
// GCD(a, b) = GCD((a-b)/2, b) (if a mod 2 = b mod 2 = 1 and  a >= b) or
// GCD(a, b) = 2*GCD(a, (b-a)/2) (if a mod 2 = b mod 2 = 1 and a < b)
LL binary_iterational_GCD(LL a, LL b){
	
	LL powOf2 = 1;
	while( a%2 == 0  &&  b%2 == 0 ){ // GCD(a/2, b/2)
		powOf2 *= 2;
		a /= 2;
		b /= 2;	
	}
	
	while( a != 0  &&  b != 0 ){
		
		if( a%2 != b%2 ){
			
			while( a%2 == 0 ){ // GCD(a/2, b)
				a /= 2;
			}
			
			while( b%2 == 0 ){ // b%2 == 0;  GCD(a, b/2)
				b /= 2;
			}
		}
		
		if( a%2 == 1  &&  b%2 == 1 ){
			
			if( a >= b ){ // GCD((a-b)/2, b)
				a = (a-b)/2;
			}
			else{ // a < b;  GCD(a, (b-a)/2)
				b = (b-a)/2;
			}
		}
	}
	
	return (a == 0) ? powOf2*b : powOf2*a; // if a = 0: return powOf2*GCD(0, b); 
							 			   //     else: return powOf2*GCD(a, 0);
}



// 9*10^18 >= a,b >= 0 and a+b > 0
LL least_absolute_remainders_iterational_GCD(LL a, LL b){
	
	LL q, r, e, tmp;
	while( b != 0 ){
		q = a / b;
		r = a - q*b; // a mod b
		e = std::abs( a - (q+1) * b );
		
		tmp = std::min( r, e );
		a = b;
		b = tmp;
	}
	
	return a;
}



int main(){
	
	LL a, b;
	
	printf( "Data input\n" );
	
	printf( "Enter first number: a = " );
	scanf( "%lld", &a );
	
	printf( "Enter second number: b = " );
	scanf( "%lld", &b );
	
	// ---------------------
	
	printf( "\nResults:\n" );
	
	// Brutal recursive GCD
	printf( "Brutal recursive GCD: GCD(%lld, %lld) = %lld\n", a, b, brutal_recursive_GCD(a, b) );
	
	// Brutal iterational GCD
	printf( "Brutal iterational GCD: GCD(%lld, %lld) = %lld\n", a, b, brutal_iterational_GCD(a, b) );
	
	// Classic recursive GCD
	printf( "Classic recursive GCD: GCD(%lld, %lld) = %lld\n", a, b, classic_recursive_GCD(a, b) );
	
	// Classic iterational GCD
	printf( "Classic iterational GCD: GCD(%lld, %lld) = %lld\n", a, b, classic_iterational_GCD(a, b) );
	
	// Binary recursive GCD
	printf( "Binary recursive GCD: GCD(%lld, %lld) = %lld\n", a, b, binary_recursive_GCD(a, b) );
	
	// Binary iterational GCD
	printf( "Binary iterational GCD: GCD(%lld, %lld) = %lld\n", a, b, binary_iterational_GCD(a, b) );
	
	// Least absolute remainders iterational GCD
	printf( "Least absolute remainders iterational GCD: GCD(%lld, %lld) = %lld\n", a, b, least_absolute_remainders_iterational_GCD(a, b) );
	
	// ---------------------
	
	return 0;
}
