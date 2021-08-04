#include<bits/stdc++.h> // AC;		C++/C++14 (gcc 8.3)


typedef std::pair <int, int> PII;
typedef std::map <PII, int> MPIII;
typedef std::vector <int> VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FOR(i,a,b,jump) for(int i=a; i<=b; i+=jump)
#define PB push_back
#define C clear
#define MP std::make_pair
#define remainder first.first
#define modulo first.second
#define counter second


int main(){
	
	int t, n, q, a, b, r, jump, count;
	
	// t - number of test cases
	scanf( "%d", &t );
	
	// For each test case
	REP(k,1,t){
		
		// n - length of sequence
		// q - number of operations 
		scanf( "%d %d", &n, &q );
		
		MPIII MAP;
		VI ans(n+1, 0);
		
		REP(i,1,q){
			scanf( "%d %d", &a, &b );
			++MAP[ MP(a%b, b) ];
		}
		
		for(auto it: MAP){
			r = it.remainder;
			jump = it.modulo;
			count = it.counter;
			
			FOR(j,r,n,jump){
				ans[j] += count;	
			}
		}
		
		printf( "Case %d: ", k );
		REP(i,1,n){
			printf( "%d ", ans[i] );
		}
		printf( "\n" );
		
		ans.C();
		MAP.C();
	}
	
	return 0;
}
