#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef vector <LL> VLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define PB push_back

#define S size


void sort2(LL &a, LL &b){
	if( a > b ){
		swap( a, b );
	}
}


vector <LL> factors(LL n){
	
	VLL result;
	
	LL i = 1;
	
	while(i*i < n){
		if( n % i == 0 ){
			result.PB( i );
			result.PB( n/i );
			
			//printf( "%lld, %lld\n", i, n/i );
			
		}
		
		++i;
	}
	
	if(i*i == n){
		result.PB(i);
		
		//printf( "%lld\n", i );
	}
	
	//printf( "\n\n\n\n" );
	
	return result;
}


int main(){
	
	LL A, B, C, D;
	scanf( "%lld %lld %lld %lld", &A, &B, &C, &D );
	
	sort2(A,B);
	
	VLL Cfactors = factors(C);    LL rC = Cfactors.S();
	VLL Dfactors = factors(D);	  LL rD = Dfactors.S();
	
	REP(i,0,rC-1){
		
		LL c = Cfactors[i];
		
		REP(j,0,rD-1){
			
			LL d = Dfactors[j];
			
			//printf( "c = %lld, d = %lld, C' = %lld, D' = %lld: ", c, d, min( (C/c)*d, (D/d)*c ),  max( (C/c)*d, (D/d)*c ) );
			
			if( min( (C/c)*d, (D/d)*c ) <= A  &&  max( (C/c)*d, (D/d)*c ) <= B ){
				printf( "TAK\n" );
				
				return 0;
			}
			/*else{
				printf( "NIE\n" );
			}*/
		}
	}
	
	printf( "NIE\n" );
	
	return 0;
}
