#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
void f(int nr, int dl)
{
	int pocz = ( nr - 1 ) * dl + 1, kon = nr * dl;
	
	REP(i,pocz,kon)
	{
		cout << i << " ";
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n; // 2|n
	
	cin >> n;
	
	REP(i,1,n)
	{
		f( i, n / 2 );
		
		f( 2 * n - i + 1, n / 2 );
		
		cout << endl;
	}
	
	return 0;
}
