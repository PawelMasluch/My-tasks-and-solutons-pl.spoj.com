#include <iostream> // 100 pkt; nieco szybsze ni¿ v2
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m; 
	
	int last_nice_mountain_number = 0;
	long long res = 0;
	int h;
	
	for(int i=1; i<=n; ++i){
		cin >> h;
		
		if( h >= m ){
			res += i;
			last_nice_mountain_number = i;
		}
		else{
			res += last_nice_mountain_number;
		}
	}
	
	cout << res << endl;
	
	return 0;
}
