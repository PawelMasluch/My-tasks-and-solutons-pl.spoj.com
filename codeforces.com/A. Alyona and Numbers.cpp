#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, m, wyn = 0;
	
	cin >> n >> m;
	
	wyn += ( n / 5 ) * ( m / 5 );
	
	REP(r,1,4)
	{
		wyn += ( ( n + r ) / 5 ) * ( ( m + 5 - r ) / 5 );
	}
	
	cout << wyn << endl;
	
	return 0;
}
