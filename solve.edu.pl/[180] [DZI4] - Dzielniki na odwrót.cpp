#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_FACTORS_NR = 16;

const LL INF = (LL)1000000000*100000000 + 1; // 10^17 + 1



int primes[MAX_FACTORS_NR] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int t[MAX_FACTORS_NR];

//int factor_nr = 1;

LL result = INF;

void rozklad(int N, int min_dzielnik, int curr_factors_nr, int *t){
	if(N == 1){
		
		//printf( "%d: ", factor_nr );
		
		
		/*REP(i,0,curr_factors_nr-1){
			printf( "%d ", t[i] );
		}
		printf( "\n" );
		*/
		
		LL M = 1;
		
		FORD(i,curr_factors_nr-1,0){
			REP(j,1,t[i]-1){
				M *= primes[curr_factors_nr-1-i];
				
				if( M >= INF ){
					//factor_nr++;
					return;
				}
			}
		}
		
		//printf( "\n%d: %lld\n", factor_nr++, M );
		
		result = (M < result) ? M : result;
		return;
	}
	else{
		REP(k,min_dzielnik,N){
			if( N % k == 0 ){
				t[ curr_factors_nr ] = k;
				
				rozklad(N/k, k, curr_factors_nr+1, t);
			}
		}
	}
}


int main(){
	
	int N;
	scanf( "%d", &N );
	
	rozklad(N,2,0,t);
	
	if( result == INF ){
		printf( "NIE\n" );
	}
	else{
		printf( "%lld\n", result );
	}
	
	return 0;
}
