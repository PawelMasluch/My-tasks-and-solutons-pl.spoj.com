#include<iostream> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;
const int MODULO = 1000000007;


int count[MAX_N+1];


int main(){
	
	ios_base::sync_with_stdio(0);
	
	// ------------------------------
	
	int n;
	cin >> n; // 1 <= n <= MAX_N 
	
	// ------------------------------
	
	int a_i;
	REP(i,1,n){
		
		cin >> a_i; // 1 <= a_i <= n
		
		++count[ a_i ]; 
	}
	
	// ------------------------------
	
	int howMany = 0;
	LL res = 1;
	FORD(i,n,1){
		
		howMany += count[i];
		
		res = (res * howMany) % MODULO;
		
		--howMany;
	}
	
	// ------------------------------
	
	cout << res << endl;
	
	// ------------------------------
	
	return 0;
}
