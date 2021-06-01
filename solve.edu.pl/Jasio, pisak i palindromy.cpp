#include<iostream> // 100 pkt
#include<new>
#include<string>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int r, i, j, **DP, ile;
	
	cin >> s;
	
	r = s.size();
	
	DP = new int *[r+1];
	
	REP(i,r+1)
	{
		DP[i] = new int [r+1];
	}
	
	REP(i,r+1)
	{
		DP[i][0] = 0;
	}
	
	REP(j,r+1)
	{
		DP[0][j] = 0;
	}
	
	REP(i,r)
	{
		REP(j,r)
		{
			ile = ( s[i] == s[ r - j - 1 ] ) ? 1 : 0 ;
			
			DP[ i + 1 ][ j + 1 ] = max( DP[i][ j + 1 ], max( DP[ i + 1 ][j], DP[i][j] + ile ) );
		}
	}
	
	cout << DP[r][r] << endl;
	
	return 0;
}
