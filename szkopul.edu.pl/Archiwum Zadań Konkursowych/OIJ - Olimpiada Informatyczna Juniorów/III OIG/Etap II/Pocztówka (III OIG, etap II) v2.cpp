#include <cstdio> // 100 pkt
using namespace std;

int main() {
	
	int n, m;
	scanf( "%d %d", &n, &m );
	
	int last_nice_mountain_number = 0;
	long long res = 0;
	int h;
	
	for(int i=1; i<=n; ++i){
		scanf( "%d", &h );
		
		if( h >= m ){
			res += i;
			last_nice_mountain_number = i;
		}
		else{
			res += last_nice_mountain_number;
		}
	}
	
	printf( "%lld\n", res );
	
	return 0;
}
