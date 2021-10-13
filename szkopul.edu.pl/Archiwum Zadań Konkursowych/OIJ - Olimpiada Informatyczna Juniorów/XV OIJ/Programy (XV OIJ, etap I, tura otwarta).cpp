#include<iostream> // 100 pkt
#include<stack>
#include<algorithm>


using namespace std;


typedef stack <int> SI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define P push
#define p pop
#define E empty


int main(){
	
	ios_base::sync_with_stdio(0);
	
	// -------------------
	
	int N;
	cin >> N;
	
	int A[N];
	REP(i,0,N-1){
		cin >> A[i];
	}
	
	// -------------------
	
	int M;
	cin >> M;
	
	int B[M];
	REP(i,0,M-1){
		cin >> B[i];
	}
	
	// -------------------
	
	sort( A, A + N );
	
	sort( B, B + M );
	
	// -------------------
	
	int res = 0;
	
	SI S;
	
	int i = 0, j = 0;
	
	while( j < M ){
		while( i < N  &&  A[i] <= B[j] ){
			
			S.P( A[i] );
			
			++i;
		}
		
		if( !S.E() ){
			
			++res;
			
			S.p();
		}
		
		++j;
	}
	
	cout << res << endl;
	
	return 0;
	
}
