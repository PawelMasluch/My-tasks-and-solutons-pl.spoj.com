#include<iostream> // 100 pkt
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int main(){
	
	ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	int t[N];
	REP(i,0,N-1){
		cin >> t[i];
	}
	
	sort( t, t+N );
	
	int i = 2, res = 0;
	while( i < N ){
		
		if( t[i] - t[i-2] <= 1 ){
			++res;
			i += 3;
		}
		else{
			++i;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
