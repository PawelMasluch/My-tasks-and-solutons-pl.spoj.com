#include<cstdio> // 100 pkt
#include<new>
#include<vector>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)


using namespace std;


const int p = 1000000007;


vector < int > V;

int rozm = 0;


int f(int &n)
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


void aktualizuj(int **DP, int &r, int u, int j)
{
	while( u )
	{
		DP[u][j] = ( DP[ ( u << 1 ) ][j] + DP[ ( u << 1 ) + 1 ][j] ) % p;
		
		u >>= 1;
	}
}


void bazowe(int v, int lewy, int prawy, int a, int b) //'v' jest numerem węzła w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.push_back(v);
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) >> 1;
	
	if ( prawy <= sr )
	{
		bazowe( ( v << 1 ), lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( ( v << 1 ) + 1, lewy, prawy, sr + 1, b );
		}
		else
		{
			bazowe( ( v << 1 ), lewy, sr, a, sr );
			
			bazowe( ( v << 1 ) + 1, sr + 1, prawy, sr + 1, b );
		}
	}
}


int query(int **DP, int r, int pocz, int kon, int j)
{
	int i, wyn = 0;
	
	bazowe( 1, pocz, kon, 0, r - 1 );
	
	REP(i,0,rozm-1)
	{
		wyn = ( wyn + DP[ V[i] ][j] ) % p;
	}
	
	V.clear();
	
	rozm = 0;
	
	return wyn;
}


int main()
{
	int N, K, *t, r, **DP, i, j, temp;
	
	scanf("%d%d", &N, &K);
	
	r = f(N);
	
	t = new int [r];
	
	REP(i,0,N-1)
	{
		scanf( "%d", &t[i] );
		
		--t[i];
	}
	
	REP(i,N,r-1)
	{
		t[i] = i;
	}
	
	DP = new int *[ ( r << 1 ) ];
	
	REP(i,1,(r << 1)-1)
	{
		DP[i] = new int [K+1];
		
		REP(j,0,K)
		{
			DP[i][j] = 0;
		}
	}
	
	REP(i,0,r-1)
	{
		temp = r + t[i];
		
		DP[ temp ][1] = 1;
		
		aktualizuj( DP, r, ( temp >> 1 ), 1 );
		
		if( t[i] == r - 1 )
		{
			REP(j,2,K)
			{
				DP[temp][j] = 0;
			}
		}
		else
		{
			REP(j,2,K) // każda j-inwersja
			{
				DP[temp][j] = query( DP, r, t[i] + 1, r - 1, j - 1 ); // wynik dla liścia
				
				aktualizuj( DP, r, ( temp >> 1 ), j ); // reszta drzewa
			}
		}
	}
	
	printf( "%d\n", query( DP, r, 0, N - 1, K ) );
	
	return 0;
}
