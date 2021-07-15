#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, **DP;
	
	cin >> n;
	
	DP = new int *[n];
	
	REP(i,0,n-1)
	{
		DP[i] = new int [n];
	}
	
	DP[0][0] = 1;
	
	REP(i,1,n-1)
	{
		DP[i][0] = 1;
		
		DP[0][i] = 1;
	}
	
	REP(i,1,n-1)
	{
		REP(j,1,n-1)
		{
			DP[i][j] = DP[ i - 1 ][j] + DP[i][ j - 1 ];
		}
	}
	
	cout << DP[ n - 1 ][ n - 1 ] << endl;
	
	return 0;
}
