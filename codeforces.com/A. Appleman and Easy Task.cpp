#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	char zn;
	
	int n, **T, x[4] = { -1, 0, 1, 0 }, y[4] = { 0, 1, 0, -1 }, ile = 0;
	
	cin >> n;
	
	T = new int *[n+2];
	
	REP(i,0,n+1)
	{
		T[i] = new int [n+2];
		
		REP(j,0,n+1)
		{
			T[i][j] = 0;
		}
	}
	
	
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			cin >> zn;
			
			T[i][j] = ( zn == 'x' ) ? 0 : 1 ;
		}
	}
	
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			REP(k,0,3)
			{
				ile += T[ i - x[k] ][ j - y[k] ];
			}
			
			if( ile % 2 == 1 )
			{
				cout << "NO\n";
				
				return 0;
			}
			
			ile = 0;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}
