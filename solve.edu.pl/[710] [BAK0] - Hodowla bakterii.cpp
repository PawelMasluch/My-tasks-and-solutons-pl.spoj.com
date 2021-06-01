#include<cstdio> // 100 pkt


using namespace std;


int main(){
	int N; // 1 <= N <= 10^9
	scanf( "%d", &N );
	
	printf( "%d\n", __builtin_popcount(N) ); // a number of ones in a binary representation of N
	
	return 0;
}
