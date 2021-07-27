#include<bits/stdc++.h> // AC


typedef long long LL;


// Number of ending zeros of n! = An exponent of 5 in factorization of n!.
LL factorial_ending_zeros(LL n){
	
	LL power_of_5 = 5; // initially, 5^0
	LL res = 0;
	
	while( power_of_5 <= n ){
		res += ( n / power_of_5 );
		power_of_5 *= 5;
	}
	
	return res;
}


int main(){
	
	LL t, n;
	
	scanf( "%lld", &t );
	
	while( t-- ){
		scanf( "%lld", &n );
		printf( "%lld\n", factorial_ending_zeros(n) );
	}
	
	return 0;
}
