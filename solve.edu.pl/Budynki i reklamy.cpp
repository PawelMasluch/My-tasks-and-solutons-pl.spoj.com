#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<algorithm>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)

#define PB push_back

#define MP make_pair

#define ST first

#define D delete

#define ND second


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;

typedef vector < int > VI;


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


void wczytaj(int *T, int N)
{
	int i;
	
	REP(i,0,N-1)
	{
		scanf("%d", &T[i]);
	}
}


void przeskaluj(int *T, int *pom, int N, int &r)
{
	int i;
	
	PII *temp = new PII [N];
	
	REP(i,0,N-1)
	{
		temp[i] = MP( T[i], i );
	}
	
	sort( temp, temp + N );
	
	pom[ temp[0].ND ] = r;
	
	REP(i,1,N-1)
	{
		if( temp[i].ST != temp[i-1].ST  )
		{
			++r;
		}
		
		pom[ temp[i].ND ] = r;
	}
	
	delete [] temp;
}


int f(int r)
{
	int wyn = 1;
	
	while( wyn < r )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void inicjuj(int *DP, int r, int value)
{
	int i;
	
	REP(i,1,2*r-1)
	{
		DP[i] = value;
	}
}


VI V;

int rozm = 0;


void bazowe(int v, int lewy, int prawy, int a, int b) //'v' jest numerem węzła w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.PB(v);
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) / 2;
	
	if ( prawy <= sr )
	{
		bazowe( 2*v, lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( 2*v+1, lewy, prawy, sr+1, b );
		}
		else
		{
			bazowe( 2*v, lewy, sr, a, sr );
			
			bazowe( 2*v+1, sr+1, prawy, sr+1, b );
		}
	}
}


int query(int *DP, int r, int pocz, int kon, char zn)
{
	bazowe(1,pocz,kon,0,r-1);
	
	int wyn = DP[ V[0] ], i;
	
	if( zn == 'L' )
	{
		REP(i,1,rozm-1)
		{
			wyn = max( wyn, DP[ V[i] ] );
		}
	}
	else // zn == 'R'
	{
		REP(i,1,rozm-1)
		{
			wyn = min( wyn, DP[ V[i] ] );
		}
	}
	
	V.clear();
	
	rozm = 0;
	
	return wyn;
}


void aktualizuj(int *DP, int v, int value, char zn)
{
	DP[v] = value;
	
	v /= 2;
	
	if(zn == 'L')
	{
		while( v )
		{
			DP[v] = max( DP[2*v], DP[2*v+1] );
			
			v /= 2;
		}
	}
	else // zn == 'R'
	{
		while( v )
		{
			DP[v] = min( DP[2*v], DP[2*v+1] );
			
			v /= 2;
		}
	}
}


LL oblicz(int *T, int *pom, int N, int r)
{
	LL wyn = 0;
	
	int i, *na_lewo = new int [N], *na_prawo = new int [N], *DP = new int [2*r];
	
	inicjuj(DP,r,-1);
	
	REP(i,0,N-1)
	{
		na_lewo[i] = ( pom[i] == 0 ) ? 0 : query( DP, r, 0, pom[i] - 1, 'L' ) + 1 ;
		
		aktualizuj( DP, pom[i] + r, i, 'L' );
	}
	
	inicjuj(DP,r,N);
	
	FORD(i,N-1,0)
	{
		na_prawo[i] = ( pom[i] == 0 ) ? N - 1 : query( DP, r, 0, pom[i] - 1, 'R' ) - 1 ;
		
		wyn = max( wyn, (LL)( na_prawo[i] - na_lewo[i] + 1 ) * T[i] );
		
		aktualizuj( DP, pom[i] + r, i, 'R' );
	}
	
	D [] DP;  D [] na_lewo;  D [] na_prawo;
	
	return wyn;
}


int main()
{
	int N, r = 0;
	
	scanf("%d", &N);
	
	int *pom = new int [N], *T = new int [N];
	
	wczytaj(T,N);
	
	przeskaluj(T,pom,N,r);
	
	r = f(r+1);
	
	printf( "%lld\n", oblicz(T,pom,N,r) );
	
	D [] pom;  D [] T;
	
	return 0;
}
