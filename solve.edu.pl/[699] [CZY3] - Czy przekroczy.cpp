#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


const LL M = (LL)1000000000 * 1000000000;


int main(){
	
	int Q; // 1 <= Q <= 10^5
	scanf( "%d", &Q );
	
	LL A, B;
	
	while( Q > 0 ){
		scanf( "%lld %lld", &A, &B ); // 0 <= A,B <= 10^18
		
		if( B == 0 ){
			printf( "JEST OKEJ\n" );
		}
		else{
			if( A <= M / B ){
				printf( "JEST OKEJ\n" );
			}
			else{
				printf( "PRZEKROCZY\n" );
			}
		}
		
		--Q;
	}
	
	return 0;
}
