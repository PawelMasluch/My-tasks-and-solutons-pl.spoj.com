#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k, m, a, x = 0, temp = 0;
	
	cin >> n >> k;
	
	REP(i,1,k)
	{
		cin >> m;
		
		REP(j,1,m)
		{
			cin >> a;
			
			if( a == j )
			{
				++temp;
			}
		}
		
		x = max( x, temp );
		
		temp = 0;
	}
	
	cout << 2 * ( n - x ) - k + 1 << endl;
	
	return 0;
}
