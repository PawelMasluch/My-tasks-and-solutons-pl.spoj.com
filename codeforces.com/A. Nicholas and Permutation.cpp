#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
const int MAX_N = 100;
 
 
int n, a[MAX_N], poz1, pozn;
 
 
int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	
	REP(i,0,n-1)
	{
		cin >> a[i];
		
		if( a[i] == 1 )
		{
			poz1 = i;
		}
		
		if( a[i] == n )
		{
			pozn = i;
		}
	}
	
	if( poz1 == 0  ||  poz1 == n - 1  ||  pozn == 0  ||  pozn == n - 1 )
	{
		cout << n - 1 << endl;
	}
	else
	{
		cout << max( max( pozn - 0, n - 1 - pozn ), max( poz1 - 0, n - 1 - poz1 ) ) << endl;
	}
	
	return 0;
}
