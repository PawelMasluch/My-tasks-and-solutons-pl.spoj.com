#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k, *t, ind, wyn = 0;
	
	cin >> n >> k;
	
	t = new int [n];
	
	REP(i,0,n-1)
	{
		cin >> t[i];
	}
	
	ind = k;
	
	while( ind <= n - 1 )
	{
		if( t[ ind ] == t[ k - 1 ] )
		{
			++ind;
		}
		else
		{
			break;
		}
	}
	
	--ind;
	
	REP(i,0,ind)
	{
		if( t[i] > 0 )
		{
			++wyn;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
