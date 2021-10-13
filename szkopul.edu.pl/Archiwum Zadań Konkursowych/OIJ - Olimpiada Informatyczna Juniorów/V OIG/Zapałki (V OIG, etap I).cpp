#include<iostream> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000;


int n; // liczba zapalek; 1 <= n <= 10^6

int zwrot[MAX_N]; // zwrot[k] - zwrot glowki k-tej zapalki w ciagu: 0 - glowka w lewo, 1 - glowka w prawo

int DP_L[MAX_N]; // DP_L[k] - minimalna liczba przestawien pierwszych k zapalek, pod warunkiem, ze ostatnia zapalka ma zwrot glowki w lewo 
int DP_P[MAX_N]; // DP_L[k] - minimalna liczba przestawien pierwszych k zapalek, pod warunkiem, ze ostatnia zapalka ma zwrot glowki w prawo


int main(){
	
	ios_base::sync_with_stdio(0);
	
	// -----------------------------
	
	cin >> n;
	REP(i,0,n-1){
		cin >> zwrot[i];
	}
	
	// -----------------------------
	
	DP_L[0] = (zwrot[0] == 0)  ?  0  :  1 ;
	DP_P[0] = (zwrot[0] == 1)  ?  0  :  1 ;
	
	REP(i,1,n-1){
		
		DP_L[i] = (zwrot[i] == 0)  ?  min( DP_L[i-1], DP_P[i-1] ) :  1 + min( DP_L[i-1], DP_P[i-1] ) ;
		DP_P[i] = (zwrot[i] == 1)  ?  DP_P[i-1]  :  1 + DP_P[i-1] ;
	}
	
	// -----------------------------
	
	int res = min( DP_L[n-1], DP_P[n-1] );
	cout << res << endl;
	
	// -----------------------------
	
	return 0; 
}
