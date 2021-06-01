#include<cstdio>


using namespace std;


typedef long long LL;


const LL M = 1000000007; // modulo


// (base^exponent) mod (modulo)
LL fastPowerModulo(LL base, LL exponent, LL modulo){ // 1 <= base <= 10^9, 0 <= exponent <= 10^18,  1 <= modulo <= 10^18
	LL result = 1 % modulo;
	
	while( exponent > 0 ){
		if( exponent % 2 == 1 ){
			result = ( result * base ) % modulo;
		}
		
		base = (base*base) % modulo;
		
		exponent /= 2;
	}
	
	return result;
}


int main(){
	LL N; // 0 <= N <= 10^6
	scanf( "%lld", &N );
	
	printf( "%lld\n", fastPowerModulo(3, N, M) );
	
	return 0;
}
