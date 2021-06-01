#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000;

const int MAX_K = 10000;


int t[MAX_N+1];

int DPpref[MAX_N+2][MAX_K+1], DPsuf[MAX_N+2][MAX_K+1];

int czy_niezbedne[MAX_N+1];


int main(){
	
	int N, K;
	scanf( "%d %d", &N, &K );
	
	REP(i,1,N){
		scanf( "%d", &t[i] );
		//t[i] = i;
	}
	
	sort( t+1, t+N+1 );
	
	/*REP(i,0,N+1){
		REP(j,0,K){
			DPpref[i][j] = DPsuf[i][j] = 0;
		}
	}*/
	DPpref[0][0] = DPsuf[N+1][0] = 1;
	
	/*LLU DP[K+1];
	DP[0] = 1;
	REP(i,1,K){
		DP[i] = 0;
	}*/
	
	// DPpref
	REP(i,1,N){
		
		// Przepisywanie
		REP(j,0,K){
			DPpref[i][j] = DPpref[i-1][j];
		}
		
		// Korekta
		FORD(j,K,t[i]){
			if( DPpref[i][j] == 0 && DPpref[i][j-t[i]] == 1 ){
				DPpref[i][j] = 1;
			}
		}
	}
	
	// DPsuf
	FORD(i,N,1){
		
		// Przepisywanie
		REP(j,0,K){
			DPsuf[i][j] = DPsuf[i+1][j];
		}
		
		// Korekta
		FORD(j,K,t[i]){
			if( DPsuf[i][j] == 0 && DPsuf[i][j-t[i]] == 1 ){
				DPsuf[i][j] = 1;
			}
		}
	}
	
	/*
	puts("DPpref:\n");
	REP(i,0,N){
		REP(j,0,K){
			printf( "DPpref[%d][%d] = %d\n", i, j, DPpref[i][j] );
		}
		puts("\n");
	}
	*/
	
	/*
	puts("DPsuf:\n");
	FORD(i,N+1,1){
		REP(j,0,K){
			printf( "DPsuf[%d][%d] = %d\n", i, j, DPsuf[i][j] );
		}
		puts("\n");
	}
	*/
	
	REP(i,1,N){
		czy_niezbedne[i] = 1; // i-ta moneta jest niezbedna
	}
	
	REP(i,1,N){
		REP(j,0,K){
			if( DPpref[i-1][j] == 1 && DPsuf[i+1][K-j] == 1 ){
				czy_niezbedne[i] = 0;
			}
		}
	}
	
	int ile_niezbednych = 0;
	REP(i,1,N){
		ile_niezbednych += czy_niezbedne[i];
	}
	
	if( ile_niezbednych == 0 ){
		printf( "OK\n" );
	}
	else{
		REP(i,1,N){
			if( czy_niezbedne[i] == 1 ){
				printf( "%d ", t[i] );
			}
		}
		printf( "\n" );
	}
	
	/*REP(j,0,K){
		printf( "DP[%d] = %d\n", j, DP[j] );
	}*/
	
	return 0;
}
