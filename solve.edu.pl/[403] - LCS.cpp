#include<iostream> // 100 pkt
#include<string>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define S size


const int MAX_N = 5000;


string s[3];

int q, DP[MAX_N+1][MAX_N+1], r[3];


void wczytaj()
{
	REP(i,0,2)
	{
		cin >> s[i];
		
		r[i] = s[i].S();
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int LCS(int a, int b)
{
	REP(i,1,r[a])
	{
		REP(j,1,r[b])
		{
			if( s[a][ i - 1 ] == s[b][ j - 1 ] )
			{
				DP[i][j] = 1 + DP[ i - 1 ][ j - 1 ];
			}
			else
			{
				DP[i][j] = max( DP[i][ j - 1 ], DP[ i - 1 ][j] );
			}
		}
	}
	
	return DP[ r[a] ][ r[b] ];
}


bool podciag(int a, int b)
{
	int i = 0, j = 0;
	
	while( i < r[a]  &&  j < r[b] )
	{
		if( s[a][i] == s[b][j] )
		{
			++j;
		}
		
		++i;
	}
	
	return ( j == r[b] );
}


void query()
{
	if(  LCS( 0, 1 ) == r[2]  &  podciag( 0, 2 )  &  podciag( 1, 2 )  )
	{
		cout << "TAK\n";
	}
	else
	{
		cout << "NIE\n";
	}
}


void zapytania()
{
	cin >> q;
	
	while( q )
	{
		wczytaj();
		
		query();
		
		--q;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	zapytania();
	
	return 0;
}
