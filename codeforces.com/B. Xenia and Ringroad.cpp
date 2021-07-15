#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, m, a, last = 1, wyn = 0;
	
	cin >> n >> m;
	
	REP(i,1,m)
	{
		cin >> a;
		
		wyn += ( a - last + n ) % n;
		
		last = a;
	}
	
	cout << wyn << endl;
	
	return 0;
}
