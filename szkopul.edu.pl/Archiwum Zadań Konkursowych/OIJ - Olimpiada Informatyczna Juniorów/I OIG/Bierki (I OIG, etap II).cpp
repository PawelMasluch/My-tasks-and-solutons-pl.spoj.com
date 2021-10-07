#include<iostream> // 100 pkt
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int main(){

    int N; // 5 <= N <= 30000
    cin >> N;

    // ----------------------

    int t[N];
    REP(i,0,N-1){
        cin >> t[i];
    }
    
    // ----------------------
    
    sort( t, t + N );
    
    // ----------------------
    
    int res = 0;
    
    int i = 0, j = 2;
    while( j < N ){
    	
		while( i <= j-2  &&  t[i] + t[i+1] <= t[j] ){
    		++i;
		}
		
		res = max( res, j-i+1 );
		
		++j;
	}

	// ----------------------

    cout << res << endl;

	// ----------------------

    return 0;
}
