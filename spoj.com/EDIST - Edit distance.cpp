#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
const int MAX_N = 2e3, MAX_M = 2e3;
 
 
string a, b;
 
int DP[MAX_N+1][MAX_M+1], q, n, m;
 
 
int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}
 
 
void init()
{
	REP(i,0,MAX_N)
	{
		DP[i][0] = i;
	}
	
	REP(j,1,MAX_M)
	{
		DP[0][j] = j;
	}
}
 
 
int edit_distance()
{
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			DP[i][j] = ( a[ i - 1 ] == b[ j - 1 ] ) ? DP[ i - 1 ][ j - 1 ] : 1 + min( DP[ i - 1 ][j], min( DP[i][ j - 1 ], DP[ i - 1 ][ j - 1 ] ) ) ;
		}
	}
	
	return DP[n][m];
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	init();
	
	cin >> q;
	
	while( q )
	{
		cin >> a >> b;
		
		n = a.size();
		
		m = b.size();
		
		cout << edit_distance() << endl;
	
		--q;
	}
	
	return 0;
} 
