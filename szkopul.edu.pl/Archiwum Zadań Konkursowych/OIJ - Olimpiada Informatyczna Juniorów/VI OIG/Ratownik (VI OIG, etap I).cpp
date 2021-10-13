#include<iostream> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


int main(){
	
	ios_base::sync_with_stdio(0);
	
	LL n, k, x, y;
	cin >> n >> k >> x >> y;
	
	LL res = 0;
	LL x_i, y_i;
	REP(i,1,n){
		
		cin >> x_i >> y_i;
		
		if( (x - x_i)*(x - x_i) + (y - y_i)*(y - y_i) > k*k ){
			++res;
		}
	}
	
	cout << res << endl;
	
	return 0; 
}
